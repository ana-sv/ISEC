// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef ILHA_H
#define ILHA_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

#include "Territorio.h"

class Ilha : public Territorio {
    
public:
    
    Ilha();
    Ilha(const Ilha& orig);
    virtual ~Ilha();
    
    string show(string t) const; 
    
     virtual void update(int turno){}
     
     virtual Ilha *clone(){ return new Ilha(*this); };
    
private:
    

};

#endif /* ILHA_H */

