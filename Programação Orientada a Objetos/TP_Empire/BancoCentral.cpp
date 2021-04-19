// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#include "BancoCentral.h"

BancoCentral::BancoCentral(Imperio * imp) {
    designacao = "Banco Central";
    ident = "banco";
    custo = 3;
    imp->setMaxArmazem(5);
    imp->setCofre(5);
    accao = "[ * ] Imperio tem agora a capacidade do cofre e do armazem aumentada! ";
}

BancoCentral::BancoCentral(const BancoCentral& orig) {
    
}

BancoCentral::~BancoCentral() {
    
}

