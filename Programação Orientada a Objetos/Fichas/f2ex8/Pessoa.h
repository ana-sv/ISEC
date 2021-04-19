// Ana Videira | 2015012218 | 2020/2021

#ifndef PESSOA_H
#define PESSOA_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Pessoa {
    string nome;
    long bi;
    long nif;
    
public:
    Pessoa() = delete; //proibe construção por defeito.
    Pessoa(const string &s, long b, long n); // contrutor 

    void setNome(const string &n); // alterar nome que é privado

    string getNome()const; //aceder ao nome que é privado     
    long getBi()const;
    long getNif()const;

    string print()const; // usamos const para imprimir tudo para evitar o uso das funções getNome, getBi ....
    
    ~Pessoa(); 

};

#endif /* PESSOA_H */

