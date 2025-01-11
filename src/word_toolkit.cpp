#include "word_toolkit.hpp"
#include <algorithm>
#include <map>


/* Cost: O(n)
* El cost d'aquesta funció és O(n), on n és la longitud de l'string s.
*/
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

/* Cost: O(n log n)
* El cost d'aquesta funció és O(n log n), on n és la longitud de l'string s.
*/
string word_toolkit::anagrama_canonic(const string &s) throw() {
    string s_canon = s;
    sort(s_canon.begin(), s_canon.end());
    return s_canon;
}

/* Cost: O(n)
* El cost d'aquesta funció és O(n), on n és la longitud de la llista L. 
*/
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
