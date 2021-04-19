// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef MONTANHA_H
#define MONTANHA_H

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

class Montanha : public Continente {
    
public:
    
    Montanha();
    Montanha(const Montanha& orig);
    virtual ~Montanha();
    
    void update(int turno);
    
    virtual Montanha *clone(){ return new Montanha(*this); };
    
private:
    static int count;
    int num;

};

#endif /* MONTANHA_H */

