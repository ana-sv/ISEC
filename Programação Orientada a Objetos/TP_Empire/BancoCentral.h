// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef BANCOCENTRAL_H
#define BANCOCENTRAL_H

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

class BancoCentral : public Tecnologia {
    
public:
    BancoCentral(Imperio * imp);
    BancoCentral(const BancoCentral& orig);
    virtual ~BancoCentral();
   
    virtual BancoCentral *clone(){ return new BancoCentral(*this); };

    
private:

};

#endif /* BANCOCENTRAL_H */

