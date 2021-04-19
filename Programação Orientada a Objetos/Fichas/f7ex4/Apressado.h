// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef APRESSADO_H
#define APRESSADO_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#include "Tarifario.h"

//Apenas é necessario redefinir caltulaPagamento
// o acesso ao numero de treinos tem que ser feito via funcao "get"
// porque os dados sao privados na classe base

class Apressado : public Tarifario {
    
public:     
    Tarifario * duplica() const;
    
private:
   unsigned int calculaPagamento() const;

};

#endif /* APRESSADO_H */

