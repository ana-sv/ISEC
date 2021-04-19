// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Apressado.h"


Tarifario * Apressado::duplica() const {
    return new Apressado( *this );
}

unsigned int Apressado::calculaPagamento()const{
    
    unsigned int custo =0;
    unsigned int numTreinos = getNumTreinos();
    
    for( unsigned int i=0; i<numTreinos; i++ ){
        unsigned int treino = getTreino(i);
        if( treino <=10 )
            custo += 10;
        else if ( treino <= 20 )
            custo += 15;
        else
            custo +=25;
    }
    return custo;
}