// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef BOLSAVALORES_H
#define BOLSAVALORES_H

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
#include "Imperio.h"

class BolsaValores : public Tecnologia {
    
public:
    BolsaValores();
    BolsaValores(const BolsaValores& orig);
    virtual ~BolsaValores();
    
   bool techBolsaValores(Imperio * imp, string s);
   virtual BolsaValores *clone(){ return new BolsaValores(*this); };

    
    
private:
  

};

#endif /* BOLSAVALORES_H */

