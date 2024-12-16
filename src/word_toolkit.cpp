#include "word_toolkit.hpp"

#include <algorithm> // Necesario para sort

bool word_toolkit::es_canonic(const string &s) throw()
{
    for (unsigned int i = 0; i < s.size() - 1; i++)
    {
        if (s[i + 1] < s[i])
            return false;
    }
    return true;
}

string word_toolkit::anagrama_canonic(const string &s) throw()
{
    string s_canon = s;
    sort(s_canon.begin(), s_canon.end()); // Ordena el string
    return s_canon;
}

char word_toolkit::mes_frequent(const string &excl, const list<string> &L) throw()
{
    string l = anagrama_canonic(L);

    int contador = 0;   // guarda el contador del caracter actual
    int max = 0;        // guarda el numero de veces que se repite el caracter más frecuente
    char actual = l[0]; // guarda el caracter actual
    char freq = l[0];   // guarda el caracter mas frecuente
    for (unsigned int i = 0; i < l.size() - 1; i++)
    {
        if (l[i] == actual)
        {
            contador++;
            if (contador > max)
            {
                max = contador;
                freq = s.[i];
            }
        }
        else
        {
            contador = 1;
            actual = l[i];
        }
    }
    return freq;
}

/*
char word_toolkit::mes_frequent(const string &excl, const list<string> &L) throw()
{
    // Array para marcar las letras excluidas ('A' a 'Z')
    bool excl_set[26] = {false}; // Inicializado a falso

    // Marcar los caracteres en el string excl
    for (unsigned int i = 0; i < excl.size(); ++i)
    {
        excl_set[excl[i] - 'A'] = true;
    }

    // Verificar si todas las letras están excluidas
    bool all_excluded = true;
    for (int i = 0; i < 26; ++i)
    {
        if (!excl_set[i])
        {
            all_excluded = false;
            break;
        }
    }
    if (all_excluded)
        return '\0';

    // Array para contar la frecuencia de cada letra ('A' a 'Z')
    int freq[26] = {0};

    // Recorrer la lista de palabras y contar frecuencias
    for (list<string>::const_iterator it = L.begin(); it != L.end(); ++it)
    {
        const string &word = *it;
        for (unsigned int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'A';
            if (!excl_set[index]) // Si el carácter no está excluido
            {
                freq[index]++;
            }
        }
    }

    // Encontrar el carácter más frecuente
    char freq_char = '\0';
    int max_count = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (freq[i] > max_count || (freq[i] == max_count && freq_char > ('A' + i)))
        {
            max_count = freq[i];
            freq_char = 'A' + i;
        }
    }

    return freq_char;
}
*/