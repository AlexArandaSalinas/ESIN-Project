#include "anagrames.hpp"
#include "word_toolkit.hpp"

/* Pre:  Cert
   Post: Construeix un anagrama buit.
   Cost: O(1). */
anagrames::anagrames() throw(error)
{
   diccionari();
}

/* Tres grans. Constructor per còpia, operador d'assignació i destructor. */

/* Pre:  Cert
   Post: Crea una còpia de l'objecte anagrames A.
   Cost: O(n + m), on n és el nombre de paraules al diccionari i
         m és el nombre d'anagrames al mapa. */
anagrames::anagrames(const anagrames &A) throw(error)
{
   *this = A;  // Cost: O(n + m)
}

/* Pre:  Cert
   Post: Assigna l'objecte A a l'objecte actual.
   Cost: O(n + m), on n és el nombre de paraules al diccionari i
         m és el nombre d'anagrames al mapa. */
anagrames &anagrames::operator=(const anagrames &A) throw(error)
{
   if (this != &A)
   {
      diccionari::operator=(A);  // Cost: O(n), on n és el nombre de paraules al diccionari
      _anagrames_map = A._anagrames_map;  // Cost: O(m), on m és el nombre d'anagrames al mapa
   }
   return *this;
}

/* Pre:  Cert
   Post: Destrueix l'objecte anagrames.
   Cost: O(1) (el destructor per defecte s'encarrega de gestionar la memòria). */
anagrames::~anagrames() throw()
{
   // No necesitamos hacer nada especial
}

/* Pre:  Cert
   Post: Afegeix la paraula p a l'anagrama; si la paraula p ja
   formava part de l'anagrama, l'operació no té cap efecte.
   Cost: O(log m + t), on m és el nombre d'anagrames al mapa i
         t és la longitud de la paraula p. */
void anagrames::insereix(const string &p) throw(error)
{
   string canonic = word_toolkit::anagrama_canonic(p);  // Cost: O(t log t), on t és la longitud de p
   _anagrames_map[canonic].push_back(p);  // Cost: O(log m) per accedir al mapa i O(1) per inserir
   diccionari::insereix(p);  // Cost: O(log n), on n és el nombre de paraules al diccionari
}

/* Pre:  Cert
   Post: Retorna la llista de paraules p tals que anagrama_canonic(p)=a.
   Llança un error si les lletres de a no estan en ordre ascendent.
   Cost: O(log m + k log k), on m és el nombre d'anagrames al mapa i
         k és el nombre de paraules a la llista retornada. */
void anagrames::mateix_anagrama_canonic(const string &a, list<string> &L) const throw(error)
{
   if (!word_toolkit::es_canonic(a))  // Cost: O(t), on t és la longitud de a
   {
      throw error(NoEsCanonic);
   }
   map<string, list<string> >::const_iterator it = _anagrames_map.find(a);  // Cost: O(log m)
   if (it != _anagrames_map.end())
   {
      L = it->second;  // Cost: O(k), on k és la mida de la llista de paraules
      L.sort();        // Cost: O(k log k), per ordenar la llista
      L.unique();      // Cost: O(k), per eliminar duplicats
   }
   else
   {
      L.clear();  // Cost: O(1)
   }
}
