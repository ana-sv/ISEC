// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#ifndef INICIAL_H
#define INICIAL_H

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

class Inicial : public Territorio {
    
public:
    Inicial();
    Inicial(const Inicial& orig);
    virtual ~Inicial();
    
    void update(int turno);
    virtual Inicial *clone(){ return new Inicial(*this); };
    
private:

};

#endif /* INICIAL_H */

