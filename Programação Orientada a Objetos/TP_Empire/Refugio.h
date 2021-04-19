// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef REFUGIO_H
#define REFUGIO_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

#include "Territorio.h"
#include "Ilha.h"

class Refugio : public Ilha {
    
public:
    Refugio();
    Refugio(const Refugio& orig);
    virtual ~Refugio();
    
    void update(int turno) ;
    
    virtual Refugio *clone(){ return new Refugio(*this); };
    
private:
    static int count;
    int num;
     

};

#endif /* REFUGIO_H */

