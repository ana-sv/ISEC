// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#ifndef INVASAO_H
#define INVASAO_H

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

class Invasao : public Evento {
    
public:
    Invasao();
    Invasao(const Invasao& orig);
    virtual ~Invasao();
    
     bool eventAction(Imperio * imp, Mundo * m ); 
     
     virtual Invasao *clone(){ return new Invasao(*this); };
    
private:
    int forcaInvasao;

};

#endif /* INVASAO_H */

