// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef ABANDONADO_H
#define ABANDONADO_H

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

class Abandonado : public Evento {
    
public:
    Abandonado();
    Abandonado(const Abandonado& orig);
    virtual ~Abandonado();
    
    bool eventAction(Imperio * imp, Mundo * m ); 
    virtual Abandonado *clone(){ return new Abandonado(*this); };

    
private:
    

};

#endif /* ABANDONADO_H */

