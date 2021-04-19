// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#ifndef FORTALEZA_H
#define FORTALEZA_H

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

class Fortaleza : public Territorio {
    
public:
    Fortaleza();
    Fortaleza(const Fortaleza& orig);
    virtual ~Fortaleza();
    
    void update(int turno);

    virtual Fortaleza *clone(){ return new Fortaleza(*this); };
    
private:
    static int count;
    int num;

};

#endif /* FORTALEZA_H */

