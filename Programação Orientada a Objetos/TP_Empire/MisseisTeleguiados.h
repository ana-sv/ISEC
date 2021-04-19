// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef MISSEISTELEGUIADOS_H
#define MISSEISTELEGUIADOS_H

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

class MisseisTeleguiados : public Tecnologia {
    
public:
    MisseisTeleguiados();
    MisseisTeleguiados(const MisseisTeleguiados& orig);
    virtual ~MisseisTeleguiados();
    
    virtual MisseisTeleguiados *clone(){ return new MisseisTeleguiados(*this); };
        
private:
    

};

#endif /* MISSEISTELEGUIADOS_H */

