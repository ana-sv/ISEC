// Ana Videira | 2015012218 | 2020/2021

// Banco & Conta » relacao de composicao 
// Pessoa & Conta » relacao de agregacao

#ifndef CONTA_H
#define CONTA_H

#include "Pessoa.h"


class Conta {
    int saldo;
    Pessoa *titular; 
    
public:
    Conta( Pessoa *p);
    ~Conta();
    
    void getInfoConta(ostringstream &oss) const;
    Pessoa * getTitular() const;
    int getSaldo() const;
    
    int setSaldo( int s );
    

};

#endif /* CONTA_H */

