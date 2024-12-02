#include "anagrames.hpp"

/* Pre:  Cert
   Post: Construeix un anagrama buit. */
anagrames() throw(error)
{
}

/* Tres grans. Constructor per còpia, operador d'assignació i destructor. */
anagrames::anagrames(const anagrames &A) throw(error)
{
}

anagrames::anagrames anagrames::&operator=(const anagrames &A) throw(error)
{
}
anagrames::~anagrames() throw()
{
}

/* Pre:  Cert
   Post: Afegeix la paraula p a l'anagrama; si la paraula p ja
   formava part de l'anagrama, l'operació no té cap efecte. */
void anagrames::insereix(const string &p) throw(error)
{
}

/* Pre:  Cert
   Post: Retorna la llista de paraules p tals que anagrama_canonic(p)=a.
   Llança un error si les lletres de a no estan en ordre ascendent. */
void anagrames::mateix_anagrama_canonic(const string &a, list<string> &L) const throw(error)
{
}