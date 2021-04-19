// Ana Videira | 2015012218 | 2020/2021

// Banco & Conta » relacao de composicao 

#ifndef BANCO_H
#define BANCO_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Pessoa.h"
#include "Conta.h"

using namespace std;

class Banco {
    string nome;
    vector <Conta> v;
    
public:
    Banco( const string &s);
    ~Banco();
    
    void getInfo(ostringstream &oss) const; 
    
    void addConta( const Conta &c); 

};

#endif /* BANCO_H */

