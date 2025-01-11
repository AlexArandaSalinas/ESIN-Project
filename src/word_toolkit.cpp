#include "word_toolkit.hpp"
#include <algorithm>
#include <map>

/* Cost: O(n)
 * El cost d'aquesta funció és O(n), on n és la longitud de l'string s.
 */
bool word_toolkit::es_canonic(const string &s) throw()
{

    if (s.length() == 0)
    {
        return true;
    }

    for (unsigned int i = 0; i < s.length() - 1; i++)
    {
        if (s[i + 1] < s[i])
        {
            return false;
        }
    }
    return true;
}

/* Cost: O(n log n)
 * El cost d'aquesta funció és O(n log n), on n és la longitud de l'string s.
 */
string word_toolkit::anagrama_canonic(const string &s) throw()
{
    string strCanon = s;
    sort(strCanon.begin(), strCanon.end());
    return strCanon;
}

/* Cost: O(n)
 * El cost d'aquesta funció és O(n), on n és la longitud de la llista L.
 */
char word_toolkit::mes_frequent(const string &excl, const list<string> &L) throw()
{

    map<char, int> freq;

    map<char, bool> excluded;
    for (char c : excl)
    {
        if (c >= 'A' && c <= 'Z')
        {
            excluded[c] = true;
        }
    }

    for (const string &paraula : L)
    {
        for (char c : paraula)
        {
            if (c >= 'A' && c <= 'Z' && !excluded[c])
            {
                freq[c]++;
            }
        }
    }

    char result = '\0';
    int max_freq = -1;

    for (const pair<const char, int> &pair : freq)
    {
        char c = pair.first;
        int count = pair.second;
        if (count > max_freq || (count == max_freq && c < result))
        {
            max_freq = count;
            result = c;
        }
    }

    return result;
}
