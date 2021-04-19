// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef CASTELO_H
#define CASTELO_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

#include "Continente.h"
#include "Territorio.h"

class Castelo : public Continente {
    
public:
    Castelo();
    Castelo(const Castelo& orig);
    virtual ~Castelo();
    
    void update(int turno) ;
    virtual Castelo *clone(){ return new Castelo(*this); };

private:
    static int count;
    int num;
     

};

#endif /* CASTELO_H */

