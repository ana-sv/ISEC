// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#include "Sociavel.h"
#include "Ginasio.h"

Sociavel::Sociavel(string n, unsigned int b, Tarifario * t)
: Cliente(n, b, t) {

}

void Sociavel::reageSaida( Ginasio * g) {
    
    if( g->getNumClientesATreinar() == 1 ) // se só está ele no ginasio
        g.saiClienteDoTreino( getBI() ); 

}

string Sociavel::getAsString()const{
    ostringstream oss;
    oss << "Sociavel - " << Cliente::getAsString();
    return oss.str();
}