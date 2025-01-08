#include "obte_paraules.hpp"
#include "iter_subset.hpp"
#include "word_toolkit.hpp"

// Ya que no hi ha un .rep, i no es poden modificar els .hpp, he posat aqui les funcions privades.
bool comparar(const string &a, const string &b);
void sortList(list<string> &paraules);

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
      for (size_t i = 0; i < subset.size(); ++i)
      {
         combination += s[subset[i] - 1];
      }
      list<string> temp;
      A.mateix_anagrama_canonic(word_toolkit::anagrama_canonic(combination), temp);
      paraules.insert(paraules.end(), temp.begin(), temp.end());
      ++it;
   }

   sortList(paraules);

   paraules.unique();
}

/* Pre:  Cert
   Post: Retorna la llista de paraules que es poden formar usant 3 o més lletres
   de la paraula s. La llista estarà ordenada de menys a més longitud;
   a igual longitud les paraules estan en ordre alfabètic creixent.
   Llança un error si l'string s té menys de tres lletres. */
void obte_paraules::obte_paraules(const string &s, const anagrames &A, list<string> &paraules) throw(error)
{
   if (s.length() < 3)
   {
      throw error(LongitudInvalida);
   }

   paraules.clear();
   for (nat k = 3; k <= s.length(); ++k)
   {
      iter_subset it(s.length(), k);
      while (!it.end())
      {
         const vector<nat> &subset = *it;
         string combination;
         for (size_t i = 0; i < subset.size(); ++i)
         {
            combination += s[subset[i] - 1];
         }
         list<string> temp;
         A.mateix_anagrama_canonic(word_toolkit::anagrama_canonic(combination), temp);
         paraules.insert(paraules.end(), temp.begin(), temp.end());
         ++it;
      }
   }

   sortList(paraules);

   paraules.unique();
}

// Funciones privadas

/*
Pre: Cert
Post: Devuelve true si la palabra 'a' es menor que la palabra 'b' tamaño.
      Si tienen la misma longitud, se compara lexicográficamente.
*/
bool comparar(const string &a, const string &b)
{
   if (a.length() != b.length())
   {
      return a.length() < b.length(); // Primero por longitud
   }
   return a < b; // Si tienen la misma longitud, orden lexicográfico
}

/* Pre: Cert
   Post: Ordena la lista de palabras 'l' de menor a mayor longitud y, en caso de empate,
         de menor a mayor lexicográficamente */
void sortList(list<string> &l)
{
   l.sort(comparar); // Usando la función de comparación
}
