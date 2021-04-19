// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef CONTINENTE_H
#define CONTINENTE_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

#include "Territorio.h"


class Continente : public Territorio {
    
public:
    Continente();
    Continente(const Continente& orig);
    virtual ~Continente();
    
    string show(string t) const; 
    
    virtual void update(int turno){ }; 
    virtual Continente *clone(){ return new Continente(*this); };
    
private:    

};

#endif /* CONTINENTE_H */

