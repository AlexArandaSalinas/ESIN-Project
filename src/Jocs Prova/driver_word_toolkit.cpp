#include "word_toolkit.hpp"
#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

int main() {
    ifstream infile("word1.in");
    ofstream outfile("output.res");

    if (!infile) {
        cerr << "No s'ha pogut obrir el fitxer d'entrada." << endl;
        return 1;
    }

    string command;

    while (infile >> command) {
    if (command == "es_canonic") {
        string s;
        infile >> s;
        outfile << word_toolkit::es_canonic(s) << endl;
    } 
    else if (command == "anagrama_canonic") {
        string s;
        infile >> s;
        outfile << word_toolkit::anagrama_canonic(s) << endl;
    } 
    else if (command == "mes_frequent") {
        string excl;
        infile >> excl;
        list<string> L;
        string word;
        while (infile >> word && word != "END") {
            L.push_back(word);
        }
        outfile << word_toolkit::mes_frequent(excl, L) << endl;
    } 
    else {
        outfile << "Comando desconegut: " << command << endl;
    }
}

    infile.close();
    outfile.close();

    return 0;
}
