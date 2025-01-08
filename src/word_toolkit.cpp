#include "word_toolkit.hpp"
#include <algorithm>
#include <map>


bool word_toolkit::es_canonic(const string &s) throw() {

    if(s.length() == 0){
        return true;
    }

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

/* Pre: L és una llista no buida de paraules formades exclusivament
        amb lletres majúscules de la 'A' a la 'Z' (excloses la 'Ñ', 'Ç',
        majúscules accentuades, ...). 
   Post: Retorna el caràcter que no apareix a l'string excl i és
        el més freqüent en la llista de paraules L.
        En cas d'empat, es retornaria el caràcter alfabèticament menor.
        Si l'string excl inclou totes les lletres de la 'A' a la 'Z' es 
        retorna el caràcter '\0', és a dir, el caràcter de codi ASCII 0. */
char word_toolkit::mes_frequent(const string &excl, const list<string> &L) throw() {
    
    // Map para contar las frecuencias de las letras
    map<char, int> freq;

    // Conjunto de caracteres excluidos
    map<char, bool> excluded;
    for (char c : excl) {
        if (c >= 'A' && c <= 'Z') {
            excluded[c] = true;
        }
    }

    // Contar las frecuencias de las letras en la lista de palabras
    for (const string& word : L) {
        for (char c : word) {
            if (c >= 'A' && c <= 'Z' && !excluded[c]) {
                freq[c]++;
            }
        }
    }

    // Encontrar el carácter más frecuente que no está excluido
    char result = '\0';
    int max_freq = -1;
    for (const auto& pair : freq) {
        char c = pair.first;
        int count = pair.second;
        if (count > max_freq || (count == max_freq && c < result)) {
            max_freq = count;
            result = c;
        }
    }

    return result;
}
