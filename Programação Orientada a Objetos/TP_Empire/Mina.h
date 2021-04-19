// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#ifndef MINA_H
#define MINA_H

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

class Mina : public Continente {
    
public:

    Mina();
    Mina(const Mina& orig);
    virtual ~Mina();

    void update(int turno);
    
    virtual Mina *clone(){ return new Mina(*this); };

private:
    static int count;
    int num;
    

};

#endif /* MINA_H */

