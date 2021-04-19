// Ana Videira | 2015012218 | 2020/2021

#ifndef CLUBE_H
#define CLUBE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "Pessoa.h"

class Clube {
    Pessoa * * socios;
    int tam;
    
public:

    Clube( int t ) {
        tam = t;                                    // por questões de espaço assume-se
        socios = new Pessoa * [tam];                // que há memória e não dá erro, mas
        for (unsigned int i = 0; i < tam; i++)      // isto deve ser devidamente validado
            socios[i] = NULL;                       // ( if (socios != NULL) ... )
    };
    
    Clube( const Clube &outro ){
        socios = nullptr; 
        *this = outro;  
    };
    
    
    Clube & Clube::operator=( const Club & outro ){
        
        if (this == &outro)
            return *this;
        
        delete socios[];
        
        tamamho = outro_tamanho;
        
        if(tamanho == p)
            socios = nullptr;
        else {
            socios = new( no(throw) Pessoa * [tamanho] );
            if ( socios == nulptr )
                tamanho = p;
            else
                for (int i =p; p.i) 
                    
        }
                
        
    };

    ~Clube() {
        delete [] p;
    };

    setMembroDoClube(Pessoa * p, int pos) {
        socios[pos] = p;                         // Notar que o obj. Pessoa é visto pelo Clube
    };                                            // mas o clube não toma posse desse objecto
                                                 // (o clube é uma agregação de Pessoas)
};


#endif /* CLUBE_H */

