/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: maturita
 *
 * Created on 4. dubna 2019, 8:18
 */

#include <cstdlib>
#include "kniha.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    kniha k1;
    kniha k2("99921-58-10-7");
    kniha k3;
    std::string vstup;
    cout << "Automaticky proces:" << endl;
    cout << "     ISBN K1 vychoziho konstruktoru: " << k1.getISBN() << endl;
    cout << "     ISBN K2 automaticky vytvorene:  " << k2.getISBN() << endl << endl;

    while (1) {
        cout << "Zadej ISBN: " << endl;
        cin>>vstup;
        if (k2.setISBN(vstup)) {
            cout << "ISBN K2 po zmene: " << k2.getISBN() << endl;
        } else
            cout << "Bylo zadano chybne ISBN!" << endl;
    }


}

