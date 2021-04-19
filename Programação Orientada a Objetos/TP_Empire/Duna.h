// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef DUNA_H
#define DUNA_H

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

class Duna : public Continente {
public:
    Duna();
    Duna(const Duna& orig);
    virtual ~Duna();
    void update(int turno);
    
    virtual Duna *clone(){ return new Duna(*this); };

private:
    static int count;
    int num;

};

#endif /* DUNA_H */

