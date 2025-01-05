#include "diccionari.hpp"
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iterator>

// Constructor
diccionari::diccionari() throw(error) : root(nullptr) {}

// Constructor per còpia
diccionari::diccionari(const diccionari& D) throw(error) {
    root = copy(D.root);
}

// Operador d'assignació
diccionari& diccionari::operator=(const diccionari& D) throw(error) {
    if (this != &D) {
        clear(root);
        root = copy(D.root);
    }
    return *this;
}

// Destructor
diccionari::~diccionari() throw() {
    clear(root);
}

// Elimina recursivament els nodes
void diccionari::clear(Node* node) {
    if (node != nullptr) {
        clear(node->esquerre);
        clear(node->mig);
        clear(node->dret);
        delete node;
    }
}

// Còpia recursiva dels nodes
diccionari::Node* diccionari::copy(Node* node) const {
    if (node == nullptr) return nullptr;
    Node* nou_node = new Node(node->paraula);
    nou_node->esquerre = copy(node->esquerre);
    nou_node->mig = copy(node->mig);
    nou_node->dret = copy(node->dret);
    return nou_node;
}

// Insereix una paraula al diccionari
void diccionari::insereix(const string& p) throw(error) {
    if (root == nullptr) {
        root = new Node(p);
        return;
    }
    Node* node_actual = root;
    for (size_t index = 0; index < p.size(); ++index) {
        char c = p[index];
        if (c < node_actual->paraula[0]) {
            if (node_actual->esquerre == nullptr) {
                node_actual->esquerre = new Node(p);
                return;
            }
            node_actual = node_actual->esquerre;
        } else if (c == node_actual->paraula[0]) {
            if (index == p.size() - 1 && node_actual->paraula == p) return;
            if (node_actual->mig == nullptr) {
                node_actual->mig = new Node(p);
                return;
            }
            node_actual = node_actual->mig;
        } else {
            if (node_actual->dret == nullptr) {
                node_actual->dret = new Node(p);
                return;
            }
            node_actual = node_actual->dret;
        }
    }
}

// Llegeix i mostra les paraules de l'arbre en preordre
void diccionari::llegeix(Node* node) const {
    if (node == nullptr) return;
    cout << node->paraula << " ";
    llegeix(node->esquerre);
    llegeix(node->mig);
    llegeix(node->dret);
}

void diccionari::escriuArbre() const {
    llegeix(root);
}

// Retorna el prefix més llarg que coincideix amb p
string diccionari::prefix(const string& p) const throw(error) {
    string prefix_mes_llarg = "";
    prefix_aux(root, p, prefix_mes_llarg, "");
    return prefix_mes_llarg;
}

void diccionari::prefix_aux(Node* node, const string& p, 
                            string& prefix_mes_llarg, string prefix_actual) const {
    if (node == nullptr) return;

    // Comprovar si el prefix actual coincideix amb l'inici de p
    if (p.find(prefix_actual) == 0) {
        if (node->paraula != "" && p.find(node->paraula) == 0) {
            prefix_mes_llarg = node->paraula;
        }
        prefix_aux(node->mig, p, prefix_mes_llarg, prefix_actual + node->paraula);
    }
    prefix_aux(node->esquerre, p, prefix_mes_llarg, prefix_actual);
    prefix_aux(node->dret, p, prefix_mes_llarg, prefix_actual);
}

// Retorna una llista amb les paraules que compleixen el patró
void diccionari::satisfan_patro(const vector<string>& q, list<string>& L) const throw(error) {
    L.clear();
    satisfan_patro_aux(root, q, L, "");
}

void diccionari::satisfan_patro_aux(Node* node, const vector<string>& q, 
                                    list<string>& L, string paraula_actual) const {
    if (node == nullptr) return;
    if (paraula_actual.size() == q.size()) {
        bool compleix_patro = true;
        for (size_t i = 0; i < q.size(); ++i) {
            if (q[i].find(paraula_actual[i]) == string::npos) {
                compleix_patro = false;
                break;
            }
        }
        if (compleix_patro) L.push_back(paraula_actual);
    } else {
        satisfan_patro_aux(node->esquerre, q, L, paraula_actual);
        satisfan_patro_aux(node->mig, q, L, paraula_actual + node->paraula);
        satisfan_patro_aux(node->dret, q, L, paraula_actual);
    }
}

// Retorna una llista amb les paraules de longitud >= k
void diccionari::llista_paraules(nat k, list<string>& L) const throw(error) {
    llista_paraules_aux(root, k, L);
}

void diccionari::llista_paraules_aux(Node* node, nat k, list<string>& L) const {
    if (node == nullptr) return;
    llista_paraules_aux(node->esquerre, k, L);
    if (node->paraula.size() >= k) L.push_back(node->paraula);
    llista_paraules_aux(node->mig, k, L);
    llista_paraules_aux(node->dret, k, L);
}

// Retorna el nombre total de paraules al diccionari
nat diccionari::num_pal() const throw() {
    return num_pal_aux(root);
}

nat diccionari::num_pal_aux(Node* node) const throw() {
    if (node == nullptr) return 0;
    return num_pal_aux(node->esquerre) + 
           num_pal_aux(node->mig) + 
           num_pal_aux(node->dret) + 1;
}
