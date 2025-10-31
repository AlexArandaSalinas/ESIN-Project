#include "diccionari.hpp"
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iterator>

// Constructor
// Cost: O(1), ja que només inicialitza l'arrel a nullptr.
diccionari::diccionari() throw(error) : root(nullptr) {}

// Constructor per còpia
// Cost: O(n), on n és el nombre de nodes de l'arbre.
diccionari::diccionari(const diccionari& D) throw(error) {
    root = copy(D.root);
}

// Operador d'assignació
// Cost: O(n), on n és el nombre de nodes de l'arbre original i de l'arbre destí.
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
// Cost: O(n), on n és el nombre de nodes de l'arbre 
void diccionari::clear(Node* node) {
    if (node != nullptr) {
        clear(node->esquerre);
        clear(node->mig);
        clear(node->dret);
        delete node;
    }
}

// Còpia recursiva dels nodes
// Cost: O(n), on n és el nombre de nodes de l'arbre 
diccionari::Node* diccionari::copy(Node* node) const {
    if (node == nullptr) return nullptr;
    Node* nou_node = new Node(node->paraula);
    nou_node->esquerre = copy(node->esquerre);
    nou_node->mig = copy(node->mig);
    nou_node->dret = copy(node->dret);
    return nou_node;
}

// Cost: O(h), on h és l'alçada de l'arbre
void diccionari::insereix(const string& p) throw(error) {
    if (root == nullptr) {
        root = new Node(p);
        
        return;
    }

    Node* node_actual = root;
    while (true) {
        if (p < node_actual->paraula) {
            if (node_actual->esquerre == nullptr) {
                node_actual->esquerre = new Node(p);
                
                return;
            }
            node_actual = node_actual->esquerre;
        } else if (p > node_actual->paraula) {
            if (node_actual->dret == nullptr) {
                node_actual->dret = new Node(p);
                
                return;
            }
            node_actual = node_actual->dret;
        } else {
            if (node_actual->paraula == p) {  
            return;
	    }
	    
            if (node_actual->mig == nullptr) {
                node_actual->mig = new Node(p);
                
                return;
            }
            node_actual = node_actual->mig;
        }

        
    }
}



// Retorna el prefix més llarg que coincideix amb p
// Cost: O(h), on h és l'alçada de l'arbre
string diccionari::prefix(const string& p) const throw(error) {
    string prefix_mes_llarg = "";
    prefix_aux(root, p, prefix_mes_llarg, "");
    return prefix_mes_llarg;
}

// Cost: O(h), on h és l'alçada de l'arbre
void diccionari::prefix_aux(Node* node, const string& p, 
                            string& prefix_mes_llarg, string prefix_actual) const {
    if (node == nullptr) return;

    // Actualizar el prefix_actual con la palabra del nodo actual
    string nou_prefix_actual = prefix_actual + node->paraula;

    // Comprovar si el nou_prefix_actual coincideix amb l'inici de p
    if (p.find(nou_prefix_actual) == 0) {
        // Actualitzar el prefix més llarg si coincideix amb el node actual
        if (node->paraula != "" && p.find(nou_prefix_actual) == 0 && nou_prefix_actual.size() > prefix_mes_llarg.size()) {
            prefix_mes_llarg = nou_prefix_actual;
        }

        // Continuar buscant en el node del mig
        prefix_aux(node->mig, p, prefix_mes_llarg, nou_prefix_actual);
    }

    // Continuar buscant en els nodes esquerre i dret
    prefix_aux(node->esquerre, p, prefix_mes_llarg, prefix_actual);
    prefix_aux(node->dret, p, prefix_mes_llarg, prefix_actual);
}

// Cost: O(n * m), on n és el nombre de nodes de l’arbre i m és la mida del patró q
void diccionari::satisfan_patro(const vector<string>& q, list<string>& L) const throw(error) {
    L.clear();  // Ens assegurem que la llista està buida al principi

    list<string> totes_les_paraules;
    llista_paraules(q.size(), totes_les_paraules);

    for (const auto& paraula : totes_les_paraules) {
        // Comprova que la longitud de la paraula coincideixi amb el patró
        if (paraula.size() != q.size()) {
            continue;
        }

        bool coincideix = true;
        for (size_t i = 0; i < paraula.size(); ++i) {
            if (q[i].find(paraula[i]) == string::npos) {
                coincideix = false;
                break;
            }
        }
        if (coincideix) {
            L.push_back(paraula);
        }
    }
}




// Retorna una llista amb les paraules de longitud >= k
// Cost: O(n), on n és el nombre de nodes de l’arbre
void diccionari::llista_paraules(nat k, list<string>& L) const throw(error) {
    llista_paraules_aux(root, k, L);
}

// Cost: O(n), on n és el nombre de nodes de l'arbre.
void diccionari::llista_paraules_aux(Node* node, nat k, list<string>& L) const {
    if (node == nullptr) return;
    llista_paraules_aux(node->esquerre, k, L);
    if (node->paraula.size() >= k) L.push_back(node->paraula);
    llista_paraules_aux(node->mig, k, L);
    llista_paraules_aux(node->dret, k, L);
}

// Retorna el nombre total de paraules al diccionari
// Cost: O(n), on n és el nombre de nodes de l’arbre
nat diccionari::num_pal() const throw() {
    return num_pal_aux(root);
}

// Cost: O(n), on n és el nombre de nodes de l’arbre
nat diccionari::num_pal_aux(Node* node) const throw() {
    if (node == nullptr) return 0;
    return num_pal_aux(node->esquerre) + 
           num_pal_aux(node->mig) + 
           num_pal_aux(node->dret) + 1;
}
