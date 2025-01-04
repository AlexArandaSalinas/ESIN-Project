#include "word_toolkit.hpp"
#include <algorithm>

bool word_toolkit::es_canonic(const string &s) throw() {
    for (unsigned int i = 0; i < s.length() - 1; i++) {
        if (s[i + 1] < s[i])
            return false;
    }
    return true;
}

string word_toolkit::anagrama_canonic(const string &s) throw() {
    string s_canon = s;
    sort(s_canon.begin(), s_canon.end());
    return s_canon;
}

char word_toolkit::mes_frequent(const string &excl, const list<string> &L) throw() {
    string l;
    for (const auto& str : L) {
        l += str;
    }
    l = anagrama_canonic(l);

    int contador = 0;   // guarda el contador del caracter actual
    int max = 0;        // guarda el numero de veces que se repite el caracter más frecuente
    char actual = l[0]; // guarda el caracter actual
    char freq = l[0];   // guarda el caracter mas frecuente
    for (unsigned int i = 0; i < l.length() - 1; i++) {
     if (excl.find(l[i]) == string::npos) {
        if (l[i] == actual) {
            contador++;
            if (contador > max) {
                max = contador;
                freq = l[i];
            }
        } else {
            contador = 1;
            actual = l[i];
        }
    }
    }
    return freq;
}
