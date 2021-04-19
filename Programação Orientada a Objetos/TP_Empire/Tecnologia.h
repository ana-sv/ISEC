// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef TECNOLOGIA_H
#define TECNOLOGIA_H


#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <ctime>

using namespace std;


#include "Territorio.h"
class Imperio;

class Tecnologia {
    
public:
    Tecnologia();
    Tecnologia(const Tecnologia& orig );
    virtual ~Tecnologia();
    
    string getDesignacao(){ return designacao; };
    string getIdent(){ return ident; };
    int getCusto() { return custo; };
    
    void setDesignacao( string s ){ designacao = s; };
    void setCusto( int c ){ custo = c; };
   
    string show();
    string showPrice();
    
    virtual Tecnologia *clone(){ return new Tecnologia(*this); };
    
protected:
    string designacao;
    string ident; 
    string accao;
    int custo;     // em ouro  

};

#endif /* TECNOLOGIA_H */

