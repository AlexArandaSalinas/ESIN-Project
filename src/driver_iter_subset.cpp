#include <iostream>
#include "iter_subset.hpp"

using namespace std;

void test_iter_subset(nat n, nat k) {
    cout << "Testing iter_subset with n = " << n << " and k = " << k << endl;
    iter_subset it(n, k);

    // Probar el operador de preincremento y el método is_finished
    while (!it._finished) {
        vector<nat> subset = *it;
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i] << " ";
        }
        cout << endl;
        ++it;
    }

    // Probar el operador de postincremento
    it = iter_subset(n, k); // Reiniciar el iterador
    cout << "Testing post-increment operator" << endl;
    while (!it._finished) {
        vector<nat> subset = *it;
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i] << " ";
        }
        cout << endl;
        it++;
    }

    // Probar el operador de igualdad y desigualdad
    iter_subset it2(n, k);
    if (it == it2) {
        cout << "Iterators are equal" << endl;
    } else {
        cout << "Iterators are not equal" << endl;
    }

    ++it2;
    if (it != it2) {
        cout << "Iterators are not equal after increment" << endl;
    } else {
        cout << "Iterators are still equal after increment" << endl;
    }
}

int main() {
    test_iter_subset(4, 2);
    test_iter_subset(5, 3);
    test_iter_subset(3, 3);
    test_iter_subset(3, 4); // Caso donde k > n

    return 0;
}