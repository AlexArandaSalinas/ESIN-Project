#include "iter_subset.hpp"

// En la constructora o se calculan todas
// de golpe, o se van creando a necesidad de que se vayan necesitando

/* Pre:  Cert
   Post: Construeix un iterador sobre els subconjunts de k elements
   de {1, ..., n}; si k > n no hi ha res a recórrer.
   Cost: O(k). */
iter_subset::iter_subset(nat n, nat k) throw(error)
{
   _n = n;
   _k = k;
   _finished = (k > n);

   if (!_finished)
   {
      // Inicializar el primer subconjunto como los primeros `k` elementos.
      _current.resize(k);         // Cost: O(k)
      for (nat i = 0; i < k; ++i) // Cost: O(k)
      {
         _current[i] = i + 1;
      }
   }
}

/* Tres grans. Constructor per còpia, operador d'assignació i destructor. */

/* Pre:  Cert
   Post: Crea una còpia de l'objecte iter_subset its.
   Cost: O(k). */
iter_subset::iter_subset(const iter_subset &its) throw(error)
{
   _n = its._n;
   _k = its._k;
   _current = its._current; // Cost: O(k)
   _finished = its._finished;
}

/* Pre:  Cert
   Post: Assigna l'objecte its a l'objecte actual.
   Cost: O(k). */
iter_subset &iter_subset::operator=(const iter_subset &its) throw(error)
{
   if (this != &its)
   {
      _n = its._n;
      _k = its._k;
      _finished = its._finished;
      _current = its._current; // Cost: O(k)
   }
   return *this;
}

/* Pre:  Cert
   Post: Destrueix l'objecte iter_subset.
   Cost: O(1) (destructor per defecte). */
iter_subset::~iter_subset() throw()
{
   // No se requiere nada especial
}

/* Pre:  Cert
   Post: Retorna cert si l'iterador ja ha visitat tots els subconjunts
   de k elements presos d'entre n; o dit d'una altra forma, retorna
   cert quan l'iterador apunta a un subconjunt sentinella fictici
   que queda a continuació de l'últim subconjunt vàlid.
   Cost: O(1). */
bool iter_subset::end() const throw()
{
   return _finished;
}

/* Operador de desreferència.
   Pre:  Cert
   Post: Retorna el subconjunt apuntat per l'iterador;
   llança un error si l'iterador apunta al sentinella.
   Cost: O(1). */
subset iter_subset::operator*() const throw(error)
{
   if (_finished)
   {
      throw error(IterSubsetIncorr);
   }
   return _current;
}

/* Operador de preincrement.
   Pre:  Cert
   Post: Avança l'iterador al següent subconjunt en la seqüència i el retorna;
   no es produeix l'avançament si l'iterador ja apuntava al sentinella.
   Cost: O(k). */
iter_subset &iter_subset::operator++() throw()
{
   if (_finished)
   {
      return *this;
   }

   if (!next_combination(_n)) // Cost: O(k)
   {
      _finished = true;
   }

   return *this;
}

/* Operador de postincrement.
   Pre:  Cert
   Post: Avança l'iterador al següent subconjunt en la seqüència i retorna el seu valor
   previ; no es produeix l'avançament si l'iterador ja apuntava al sentinella.
   Cost: O(k). */
iter_subset iter_subset::operator++(int) throw()
{
   iter_subset temp = *this; // Cost: O(k)
   ++(*this);                // Cost: O(k)
   return temp;
}

/* Operadors relacionals. */

/* Pre:  Cert
   Post: Retorna cert si els iteradors són iguals.
   Cost: O(k). */
bool iter_subset::operator==(const iter_subset &c) const throw()
{
   if ((_k == 0 && c._k == 0) && (_finished == c._finished))
      return true;

   return (_n == c._n) && (_k == c._k) && (_finished == c._finished) && (_current == c._current); // Cost: O(k)
}

/* Pre:  Cert
   Post: Retorna cert si els iteradors són diferents.
   Cost: O(k). */
bool iter_subset::operator!=(const iter_subset &c) const throw()
{
   return !(*this == c); // Cost: O(k)
}

/* Metodes utilitat */

/* Pre:  Cert
   Post: Calcula la següent combinació de k elements de {1, ..., n};
   retorna fals si ja no hi ha més combinacions possibles.
   Cost: O(k). */
bool iter_subset::next_combination(int n)
{
   int i = _k - 1;
   while (i >= 0 && _current[i] == n - _k + i + 1) // Cost: O(k)
   {
      --i;
   }

   if (i < 0)
   {
      return false;
   }

   ++_current[i];
   for (unsigned int j = i + 1; j < _k; ++j) // Cost: O(k)
   {
      _current[j] = _current[j - 1] + 1;
   }

   return true;
}
