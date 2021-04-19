// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef DRONESMILITARES_H
#define DRONESMILITARES_H

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
class Imperio;

class DronesMilitares : public Tecnologia {
    
public:
    DronesMilitares(Imperio * imp);
    DronesMilitares(const DronesMilitares& orig);
    virtual ~DronesMilitares();   
    
    virtual DronesMilitares *clone(){ return new DronesMilitares(*this); };
    
private:
    

};

#endif /* DRONESMILITARES_H */

