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

    Pessoa(const string &s, long b, long n) : nome(s), bi(b), nif(n) {
        cout << "Objeto Pessoa criado" << endl;
    }; // contrutor 

    void setNome(const string &n) { // alterar nome que é privado
        nome = n;
    }; 

    string getNome()const { // const para aceder ao nome que é privado     
        return nome;
    }; 

    long getBi()const {
        return bi;
    };

    long getNif()const {
        return nif;
    };

    string print()const {// usamos const para imprimir tudo para evitar o uso das funções getNome, getBi ....
        ostringstream oss;
        oss << nome << "-" << bi << "-" << nif << endl;
        return oss.str();
    }
    
    ~Pessoa(){
         cout << "Objeto Pessoa destruido!" << endl;
    }

};

#endif /* PESSOA_H */

