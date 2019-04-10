/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kniha.cpp
 * Author: maturita
 * 
 * Created on 4. dubna 2019, 8:19
 */

#include "kniha.hpp"
#include <string>
#include <cstring>

kniha::kniha() {
    this->isbn = "prazdne/invalidni";
}

kniha::kniha(const kniha& orig) {
}

kniha::kniha(std::string vstup) {
    if (kontrolaISBN(vstup)) {
        this->isbn = vstup;
    } else {
        this->isbn = "prazdne/invalidni";
    }
}

kniha::~kniha() {
}

bool kniha::setISBN(std::string vstup) {
    if (kontrolaISBN(vstup)) {
        this->isbn = vstup;
        return true;
    } else {
        this->isbn = "prazdne/invalidni";
        cout << "Invalidni ISBN." << endl;
        return false;
    }
}

std::string kniha::getISBN() const {
    return this->isbn;
}

bool kniha::kontrolaISBN(std::string retezec) {
    if (retezec.length() == 13) {
        int cisloPocet = 0;
        int sumaSoucinu = 0;
        int cisloTest;
        for (int i = 0; i < retezec.length(); i++) {
            if (kontrolaZnaku(retezec.substr(i, 1)) != true) {
                return false;
            }
            switch (retezec.at(i)) {
                case 'X': if (i != 12) {
                        printf("Neplatna pozice X\n");
                        return false;
                    };
                    break;
                case '-': if (i == 0 || i == 12) {
                        printf("Neplatna pozice -\n");
                        return false;
                    } else if (retezec.at(i) == retezec.at(i - 1)) {
                        printf("Neplatna pozice -\n");
                        return false;
                    };
                    break;
                default: if (cisloPocet < 9) {
                        cisloTest = retezec.at(i) - '0';
                        sumaSoucinu += cisloTest * (10 - cisloPocet);
                        cisloPocet++;
                    } else {
                        cisloTest = retezec.at(i) - '0';
                        if ((cisloTest != (11 - (sumaSoucinu % 11)))&& (sumaSoucinu % 11 != 0)) {
                            return false;
                        }
                    }
                    break;
            }
        }
        //printf("Kontrolni cislo:%d\n", (11 - (sumaSoucinu % 11)));
        char * str = new char[retezec.length() + 1];
        strcpy(str, retezec.c_str());
        char * pch;
        int skupina = 0;
        pch = strtok(str, " ,.-");
        while (pch != NULL) {
            switch (skupina) {
                case 0: if ((atoi(pch) < 0) || (atoi(pch) > 7 && atoi(pch) < 80) || (atoi(pch) > 94 && atoi(pch) < 950) || (atoi(pch) > 989 && atoi(pch) < 9926) || (atoi(pch) > 9989 && atoi(pch) < 99901) || (atoi(pch) > 99976)) {
                        printf("Neplatna prvni skupina cisel.\n");
                        return false;
                    }
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
            }
            skupina++;
            //printf("Rozbijim: %s\n", pch);
            pch = strtok(NULL, " ,.-");

        }
        return true;
    }
    printf("Neplatna delka\n");
    return false;
}

bool kniha::kontrolaZnaku(std::string kontrolovanyZnak) {
    std::string allowed = "0123456789X-";
    for (int i = 0; i < allowed.length(); i++) {
        if (kontrolovanyZnak.compare(allowed.substr(i, 1))) {
            return true;
        }
    }
    return false;
}

