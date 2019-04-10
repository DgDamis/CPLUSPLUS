/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kniha.hpp
 * Author: maturita
 *
 * Created on 4. dubna 2019, 8:19
 */

#ifndef KNIHA_HPP
#define KNIHA_HPP
#include <iostream>
#include <string.h>
#include <string>

using std::endl;
using std::cout;
using std::cin;

class kniha {
public:
    kniha();
    kniha(const kniha& orig);
    kniha(std::string);
    virtual ~kniha();
    bool setISBN(std::string);
    std::string getISBN()const;
private:
    std::string isbn;
    bool kontrolaISBN(std::string);
    bool kontrolaZnaku(std::string);
};

#endif /* KNIHA_HPP */

