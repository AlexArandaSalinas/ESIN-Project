#include "obte_paraules.hpp"
#include "iter_subset.hpp"
#include "word_toolkit.hpp"

/* Pre:  Cert
   Post: Retorna la llista de paraules que es poden formar usant k lletres
   de la paraula s. Llança error si k és major que la longitud de
   l'string s o k < 3. */
void obte_paraules::obte_paraules(nat k, const string &s, const anagrames &A, list<string> &paraules) throw(error)
{
   if (k > s.length() || k < 3)
   {
      throw error(LongitudInvalida);
   }

   paraules.clear();
   iter_subset it(s.length(), k);
   while (!it.end())
   {
      const vector<nat> &subset = *it;
      string combination;
      for (nat index : subset)
      {
         combination += s[index - 1];
      }
      list<string> temp;
      A.mateix_anagrama_canonic(word_toolkit::anagrama_canonic(combination), temp);
      paraules.insert(paraules.end(), temp.begin(), temp.end());
      ++it;
   }
}

/* Pre:  Cert
   Post: Retorna la llista de paraules que es poden formar usant 3 o més lletres
   de la paraula s. La llista estarà ordenada de menys a més longitud;
   a igual longitud les paraules estan en ordre alfabètic creixent.
   Llança un error si l'string s té menys de tres lletres. */
void obte_paraules::obte_paraules(const string &s, const anagrames &A, list<string> &paraules) throw(error)
{
}