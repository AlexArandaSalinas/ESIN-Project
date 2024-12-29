#include "diccionari.hpp"

#define _DICCIONARI_HPP
#include <string>
#include <list>
#include <vector>
#include <esin/error>
#include <esin/util>

using namespace std;
using util::nat;

class diccionari {
public:
    diccionari() throw(error);
    diccionari(const diccionari& D) throw(error);
    diccionari& operator=(const diccionari& D) throw(error);
    ~diccionari() throw();

    void insereix(const string& p) throw(error);
    string prefix(const string& p) const throw(error);
    void satisfan_patro(const vector<string>& q, list<string>& L) const throw(error);
    void llista_paraules(nat k, list<string>& L) const throw(error);
    nat num_pal() const throw();

private:
    struct Node {
        char lletra;
        bool final_paraula;
        Node* esquerra;
        Node* mig;
        Node* dreta;

        Node(char c) : lletra(c), final_paraula(false), esquerra(nullptr), mig(nullptr), dreta(nullptr) {}
    };

    Node* arrel;
    nat num_paraules;

    void insereix(Node*& n, const string& p, nat i) throw(error);
    string prefix(Node* n, const string& p, nat i) const throw(error);
    void satisfan_patro(Node* n, const vector<string>& q, nat i, string actual, list<string>& L) const throw(error);
    void llista_paraules(Node* n, nat k, string actual, list<string>& L) const throw(error);
    void destrueix(Node* n) throw();
};

#endif

#include "diccionari.hpp"

diccionari::diccionari() throw(error) : arrel(nullptr), num_paraules(0) {}

diccionari::diccionari(const diccionari& D) throw(error) {
    // Implementació del constructor per còpia
}

diccionari& diccionari::operator=(const diccionari& D) throw(error) {
    // Implementació de l'operador d'assignació
    return *this;
}

diccionari::~diccionari() throw() {
    destrueix(arrel);
}

void diccionari::insereix(const string& p) throw(error) {
    insereix(arrel, p, 0);
}

void diccionari::insereix(Node*& n, const string& p, nat i) throw(error) {
    if (i == p.size()) return;
    if (!n) n = new Node(p[i]);
    if (p[i] < n->lletra) insereix(n->esquerra, p, i);
    else if (p[i] > n->lletra) insereix(n->dreta, p, i);
    else {
        if (i == p.size() - 1) n->final_paraula = true;
        else insereix(n->mig, p, i + 1);
    }
}

string diccionari::prefix(const string& p) const throw(error) {
    return prefix(arrel, p, 0);
}

string diccionari::prefix(Node* n, const string& p, nat i) const throw(error) {
    if (!n || i == p.size()) return "";
    if (p[i] < n->lletra) return prefix(n->esquerra, p, i);
    else if (p[i] > n->lletra) return prefix(n->dreta, p, i);
    else {
        string res = p.substr(0, i + 1);
        if (n->final_paraula) return res;
        return prefix(n->mig, p, i + 1);
    }
}

void diccionari::satisfan_patro(const vector<string>& q, list<string>& L) const throw(error) {
    satisfan_patro(arrel, q, 0, "", L);
}

void diccionari::satisfan_patro(Node* n, const vector<string>& q, nat i, string actual, list<string>& L) const throw(error) {
    if (!n || i == q.size()) return;
    if (q[i].find(n->lletra) != string::npos) {
        actual += n->lletra;
        if (i == q.size() - 1 && n->final_paraula) L.push_back(actual);
        satisfan_patro(n->mig, q, i + 1, actual, L);
        actual.pop_back();
    }
    satisfan_patro(n->esquerra, q, i, actual, L);
    satisfan_patro(n->dreta, q, i, actual, L);
}

void diccionari::llista_paraules(nat k, list<string>& L) const throw(error) {
    llista_paraules(arrel, k, "", L);
}

void diccionari::llista_paraules(Node* n, nat k, string actual, list<string>& L) const throw(error) {
    if (!n) return;
    actual += n->lletra;
    if (n->final_paraula && actual.size() >= k) L.push_back(actual);
    llista_paraules(n->mig, k, actual, L);
    actual.pop_back();
    llista_paraules(n->esquerra, k, actual, L);
    llista_paraules(n->dreta, k, actual, L);
}

nat diccionari::num_pal() const throw() {
    return num_paraules;
}

void diccionari::destrueix(Node* n) throw() {
    if (!n) return;
    destrueix(n->esquerra);
    destrueix(n->mig);
    destrueix(n->dreta);
    delete n;
}
