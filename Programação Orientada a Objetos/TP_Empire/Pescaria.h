// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef PESCARIA_H
#define PESCARIA_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

#include "Territorio.h"
#include "Ilha.h"


class Pescaria : public Ilha {
    
public:
    Pescaria();
    Pescaria(const Pescaria& orig);
    virtual ~Pescaria();
    
     void update(int turno) ;
    
    virtual Pescaria *clone(){ return new Pescaria(*this); };
    
private:
    static int count;
    int num;
};

#endif /* PESCARIA_H */

