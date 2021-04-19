// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#ifndef ALIANCA_H
#define ALIANCA_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <ctime>

using namespace std;

#include "Evento.h"
#include "Mundo.h"
#include "Imperio.h"

class Alianca : public Evento {
    
public:
    Alianca();
    Alianca(const Alianca& orig);
    virtual ~Alianca();
    
    bool eventAction(Imperio * imp, Mundo * m ); 
     virtual Alianca *clone(){ return new Alianca(*this); };

    
private:

};

#endif /* ALIANCA_H */

