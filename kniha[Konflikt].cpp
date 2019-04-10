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
#define ALLOWED "0123456789X"
#include <string>
#include <cstring>

kniha::kniha() {
    this->isbn = "prazdne";
}

kniha::kniha(const kniha& orig) {
}

kniha::kniha(std::string vstup) {
    if (kontrolaISBN(vstup)) {
        this->isbn = vstup;
    } else {
        this->isbn = "prazdne";
    }
}

kniha::~kniha() {
}

bool kniha::setISBN(std::string vstup) {
    if (kontrolaISBN(vstup)) {
        this->isbn = vstup;
        return true;
    } else {
        this->isbn = "prazdne";
        return false;
    }
}

std::string kniha::getISBN() const {
    return this->isbn;
}

bool kniha::kontrolaISBN(std::string retezec) {
    if (retezec.length() == 13) {
        for (int i = 0; i < retezec.length(); i++) {
            if (kontrolaZnaku(retezec.substr(i, 1)) != true) {
                return false;
            }
            switch (retezec.at(i)) {
                case 'X': if (i != 12)return false;
                    break;
                case '-': if (i == 0 || i == 12)return false;
                else if (retezec.at(i) == retezec.at(i-1))return false;
                    break;
            }
        }
        char * str = new char[retezec.length()+1];
        strcpy(str,retezec.c_str());
        char * pch;
        pch = strtok (str," ,.-");
        int pocetObehu = 0;
        while (pch != NULL)
        {
             printf ("Rozbijim: %s\n",pch);
             switch()
             pocetObehu++;
            pch = strtok (NULL, " ,.-");
         }
        return 0;

    }
    return false;
}

bool kniha::kontrolaZnaku(std::string kontrolovanyZnak) {
    std::string allowed = "0123456789X-";
    //for(int i = 0; i < sizeof(ALLOWED);i++){
    //    allowed.append(ALLOWED[i]);
    //}
    for (int i = 0; i < allowed.length(); i++) {
        if (kontrolovanyZnak.compare(allowed.substr(i, 1))) {
            return true;
        }
    }
    return false;
}