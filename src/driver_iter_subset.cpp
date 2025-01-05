#include <iostream>
#include "iter_subset.hpp"

using namespace std;

int main() {
    nat n = 4;
    nat k = 2;
    iter_subset it(n, k);


    while (!it._finished) {
        vector<nat> subset = *it; 
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i] << " ";
        }
        cout << endl;
        ++it;
    }

    return 0;
}