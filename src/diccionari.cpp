#include "diccionari.hpp"

// Constructor per defecte
diccionari::diccionari() throw(error)
{
  root = nullptr;
}

// Constructor per còpia
diccionari::diccionari(const diccionari &D) throw(error)
{
  root = copy(D.root);
}

// Operador d'assignació
diccionari &diccionari::operator=(const diccionari &D) throw(error)
{
  if (this != &D)
  {
    clear(root);
    root = copy(D.root);
  }
  return *this;
}

// Destructor
diccionari::~diccionari() throw()
{
  clear(root);
}

// Insereix una paraula al diccionari
void diccionari::insereix(const string &p) throw(error)
{
  root = insert(root, p, 0);
}

Node *diccionari::insert(Node *node, const string &p, int index)
{
  char c = p[index];
  if (!node)
  {
    node = new Node(c);
  }
  if (c < node->character)
  {
    node->left = insert(node->left, p, index);
  }
  else if (c > node->character)
  {
    node->right = insert(node->right, p, index);
  }
  else
  {
    if (index + 1 == p.size())
    {
      node->is_end_of_word = true;
    }
    else
    {
      node->middle = insert(node->middle, p, index + 1);
    }
  }
  return node;
}

// Retorna el prefix més llarg de p que és una paraula del diccionari
string diccionari::prefix(const string &p) const throw(error)
{
  return longest_prefix(root, p, 0, "");
}

string diccionari::longest_prefix(Node *node, const string &p, int index, string current_prefix) const
{
  if (!node)
    return current_prefix;
  char c = p[index];
  if (c < node->character)
  {
    return longest_prefix(node->left, p, index, current_prefix);
  }
  else if (c > node->character)
  {
    return longest_prefix(node->right, p, index, current_prefix);
  }
  else
  {
    current_prefix += c;
    if (node->is_end_of_word)
    {
      return longest_prefix(node->middle, p, index + 1, current_prefix);
    }
    else
    {
      return longest_prefix(node->middle, p, index + 1, current_prefix);
    }
  }
}

// Retorna les paraules que satisfan el patró especificat
void diccionari::satisfan_patro(const vector<string> &q, list<string> &L) const throw(error)
{
  // Implementació específica aquí
}

// Retorna una llista de paraules de longitud major o igual a k
void diccionari::llista_paraules(nat k, list<string> &L) const throw(error)
{
  // Implementació específica aquí
}

// Retorna el nombre de paraules en el diccionari
nat diccionari::num_pal() const throw()
{
  // Implementació específica aquí
  return 0; // Retorna el nombre de paraules
}

// Funcions auxiliars
Node *diccionari::copy(Node *node)
{
  if (!node)
    return nullptr;
  Node *new_node = new Node(node->character);
  new_node->is_end_of_word = node->is_end_of_word;
  new_node->left = copy(node->left);
  new_node->middle = copy(node->middle);
  new_node->right = copy(node->right);
  return new_node;
}

void diccionari::clear(Node *node)
{
  if (node)
  {
    clear(node->left);
    clear(node->middle);
    clear(node->right);
    delete node;
  }
