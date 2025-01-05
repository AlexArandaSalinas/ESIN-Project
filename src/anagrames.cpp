#include "anagrames.hpp"
#include "word_toolkit.hpp"

/* Pre:  Cert
   Post: Construeix un anagrama buit. */
anagrames::anagrames() throw(error)
{
   diccionari();
}

/* Tres grans. Constructor per còpia, operador d'assignació i destructor. */
anagrames::anagrames(const anagrames &A) throw(error)
{
   *this = A;
}

anagrames &anagrames::operator=(const anagrames &A) throw(error)
{
   if (this != &A)
   {
      diccionari::operator=(A);
      _anagrames_map = A._anagrames_map;
   }
   return *this;
}
anagrames::~anagrames() throw()
{
   // No necesitamos hacer nada especial
}

/* Pre:  Cert
   Post: Afegeix la paraula p a l'anagrama; si la paraula p ja
   formava part de l'anagrama, l'operació no té cap efecte. */
void anagrames::insereix(const string &p) throw(error)
{
   string canonic = word_toolkit::anagrama_canonic(p);
   _anagrames_map[canonic].push_back(p);
   diccionari::insereix(p);
}

/* Pre:  Cert
   Post: Retorna la llista de paraules p tals que anagrama_canonic(p)=a.
   Llança un error si les lletres de a no estan en ordre ascendent. */
void anagrames::mateix_anagrama_canonic(const string &a, list<string> &L) const throw(error)
{
   if (!word_toolkit::es_canonic(a))
   {
      throw error(NoEsCanonic);
   }
   map<string, list<string> >::const_iterator it = _anagrames_map.find(a);
   if (it != _anagrames_map.end())
   {
      L = it->second;
   }
   else
   {
      L.clear();
   }
}