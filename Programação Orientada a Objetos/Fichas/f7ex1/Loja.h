// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#ifndef LOJA_H
#define LOJA_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

#include "Imovel.h"

class Loja : public Imovel {
    
public:
    Loja(float a): Imovel(area){ 
        area = a;
        cout << "Loja construida!" << endl; 
    };
    virtual ~Loja(){ cout << "Loja destruida!" << endl; };
    
    
    float obtemPreco() const { return 15 * obtemArea(); };
    
     string obtemCodigo() const {
        ostringstream oss;
        oss << "loja";
        oss << getNumCodigo();
        return oss.str();    
    }
    
    string obtemDescricao() const{
        ostringstream oss;
        oss << obtemCodigo(); 
        oss << " preco:  " ;
        oss << obtemPreco();
        return oss.str();   
    }
  
   

};

#endif /* LOJA_H */

