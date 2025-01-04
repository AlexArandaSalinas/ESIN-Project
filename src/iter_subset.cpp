#include "iter_subset.hpp"

// En la constructora o se calculan todas
// de golpe, o se van creando a necesidad de que se vayan necesitando

/* Pre:  Cert
   Post: Construeix un iterador sobre els subconjunts de k elements
   de {1, ..., n}; si k > n no hi ha res a recórrer. */
iter_subset::iter_subset(nat n, nat k) throw() : n(n), k(k), finished(false)
{
   current.resize(k);
   for (nat i = 0; i < k; ++i)
   {
      current[i] = i + 1;
   }
}

/* Tres grans. Constructor per còpia, operador d'assignació i destructor. */
iter_subset::iter_subset(const iter_subset &its) throw()
{
   n = its.n;
   k = its.k;
   current = its.current;
   finished = its.finished;
}

iter_subset &iter_subset::operator=(const iter_subset &its) throw()
{
   if (this != &its)
   {
      n = its.n;
      k = its.k;
      finished = its.finished;
      current = its.current; // Copiar el estado actual del subconjunto.
   }
   return *this;
}

iter_subset::~iter_subset() throw()
{
   // No se requiere nada especial
}

/* Pre:  Cert
   Post: Retorna cert si l'iterador ja ha visitat tots els subconjunts
   de k elements presos d'entre n; o dit d'una altra forma, retorna
   cert quan l'iterador apunta a un subconjunt sentinella fictici
   que queda a continuació de l'últim subconjunt vàlid. */
bool iter_subset::end() const throw()
{
   return finished;
}

/* Operador de desreferència.
   Pre:  Cert
   Post: Retorna el subconjunt apuntat per l'iterador;
   llança un error si l'iterador apunta al sentinella. */
subset iter_subset::operator*() const throw()
{
   if (finished)
   {
      throw error(IterSubsetIncorr);
   }
   return current;
}

/* Operador de preincrement.
   Pre:  Cert
   Post: Avança l'iterador al següent subconjunt en la seqüència i el retorna;
   no es produeix l'avançament si l'iterador ja apuntava al sentinella. */
iter_subset &iter_subset::operator++() throw()
{
   if (finished)
   {
      return *this;
   }

   if (!next_combination(n))
   {
      finished = true;
   }

   return *this;
}

/* Operador de postincrement.
   Pre:  Cert
   Post: Avança l'iterador al següent subconjunt en la seqüència i retorna el seu valor
   previ; no es produeix l'avançament si l'iterador ja apuntava al sentinella. */
iter_subset iter_subset::operator++(int) throw()
{
   iter_subset temp = *this;
   ++(*this);
   return temp;
}

/* Operadors relacionals. */
bool iter_subset::operator==(const iter_subset &c) const throw()
{
   return (finished == c.finished) && (current == c.current);
}
bool iter_subset::operator!=(const iter_subset &c) const throw()
{
   return !(*this == c);
}

/*Metodes utilitat*/

/*
   Pre:
   Post:

*/

template <typename Iterator>
bool next_combination(int n)
{
   int i = k - 1;
   while (i >= 0 && current[i] == n - k + i + 1)
   {
      --i;
   }

   if (i < 0)
   {
      return false;
   }

   ++current[i];
   for (int j = i + 1; j < k; ++j)
   {
      current[j] = current[j - 1] + 1;
   }

   return true;
}
/*
template <typename Iterator>
bool next_combination(int n)
{
   int k = subset.size();
   for (int i = k - 1; i >= 0; --i)
   {
      if (subset[i] < n - (k - i - 1))
      {
         ++subset[i];
         for (int j = i + 1; j < k; ++j)
         {
            subset[j] = subset[j - 1] + 1;
         }
         return true; // Se generó una nueva combinación.
      }
   }
   return false; // No hay más combinaciones posibles.
}
*/
/* Pre: Entra un unsigned integer 'n'
   Post: Retorna el factorial de n.
*/
unsigned long long iter_subset::factorial(unsigned int n)
{
   return n <= 1 ? 1 : n * factorial(n - 1);
}