#include "diccionari.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

int main() {
    ifstream infile("diccionari.in");
    ofstream outfile("diccionari.out");

    if (!infile) {
        cerr << "No s'ha pogut obrir el fitxer d'entrada." << endl;
        return 1;
    }

    diccionari d;
    string command;

    while (infile >> command) {
        if (command == "insereix") {
            string paraula;
            infile >> paraula;
            d.insereix(paraula);
            outfile << "Insereix: " << paraula << endl;
	    
	        // Afegim una crida a escriuArbre per veure l'estat actual de l'arbre
            outfile << "Arbre actual: ";
            d.escriuArbre();
            outfile << endl;
        } 
       
   
        else if (command == "prefix") {
            string paraula;
            infile >> paraula;
            outfile << "Prefix de " << paraula << ": " << d.prefix(paraula) << endl;
        } 
             /*
        else if (command == "satisfan_patro") {
            int n;
            infile >> n;
            vector<string> patro(n);
            for (int i = 0; i < n; ++i) {
                infile >> patro[i];
            }
            list<string> resultat;
            d.satisfan_patro(patro, resultat);
            outfile << "Satisfan patró: ";
            for (const auto& p : resultat) {
                outfile << p << " ";
            }
            outfile << endl;
        } 
              */  
        else if (command == "llista_paraules") {
            nat k;
            infile >> k;
            list<string> resultat;
            d.llista_paraules(k, resultat);
            outfile << "Paraules amb longitud >= " << k << ": ";
            for (const auto& p : resultat) {
                outfile << p << " ";
            }
            outfile << endl;
        } 
    
        else if (command == "num_pal") {
            outfile << "Nombre de paraules: " << d.num_pal() << endl;
        } 
        else {
            outfile << "Comando desconegut: " << command << endl;
        } 
    }
    

    infile.close();
    outfile.close();
    return 0;
}
