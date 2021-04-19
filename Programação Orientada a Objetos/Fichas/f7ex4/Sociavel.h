// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef SOCIAVEL_H
#define SOCIAVEL_H

#include "Cliente.h"

class Sociavel : public Cliente {
    
public:
    Sociavel(string n, unsigned int b, Tarifario * t);
    
    virtual void reageEntrada( Ginasio * g);
    virtual void reageSaida(Ginasio * g);
    
    Cliente * duplica()const;
    virtual string getAsString()const;
    
private:

};

#endif /* SOCIAVEL_H */

