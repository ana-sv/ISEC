// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef PLANICIE_H
#define PLANICIE_H

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

class Planicie : public Continente {
    
public:
    
    Planicie();
    Planicie(const Planicie& orig);
    virtual ~Planicie();
    
    void update(int turno) ;
    
    virtual Planicie *clone(){ return new Planicie(*this); };
    
private:
    static int count;
    int num;
     

};

#endif /* PLANICIE_H */

