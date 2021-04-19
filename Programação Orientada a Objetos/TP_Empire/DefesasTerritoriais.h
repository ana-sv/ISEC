// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef DEFESASTERRITORIAIS_H
#define DEFESASTERRITORIAIS_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <ctime>

using namespace std;

#include "Tecnologia.h"

class DefesasTerritoriais : public Tecnologia {
public:
    DefesasTerritoriais();
    DefesasTerritoriais(const DefesasTerritoriais& orig);
    virtual ~DefesasTerritoriais();

    
    void techDefense(Territorio * t);
    virtual DefesasTerritoriais *clone(){ return new DefesasTerritoriais(*this); };

private:
    int incDefesa; // incrementa defesa em caso de invasao

};

#endif /* DEFESASTERRITORIAIS_H */

