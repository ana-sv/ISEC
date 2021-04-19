// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef GINASIO_H
#define GINASIO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cliente;


class Ginasio {
    
public:
    
    void avancaRelogio( unsigned int tempo);
    bool acrescentaCliente( Cliente * c);
    unsigned int paga( unsigned int bi );
    void entraClienteNoTreino( unsigned int bi);
    void saiClienteDoTreino( unsigned int bi);
    void removeCliente( unsigned int bi);
    unsigned int getNumClientesATreinar()const;
    unsigned int pesquisaClienteDadoBI( unsigned int bi );
    
    Ginasio();
    virtual ~Ginasio();
    
    Ginasio(const Ginasio& x);
    Ginasio & operator=( const Ginasio & x);
    
    string getAsString()const;
    
private:
    vector <Cliente *> clientes; 
    unsigned int relogio;
    unsigned int pesquisaClienteDadoBI(unsigned int bi );

};

#endif /* GINASIO_H */

