// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

class Apartamento : public Imovel {
    
public:
    
    Apartamento ();
    Apartamento(const Apartamento& orig);
    virtual ~Apartamento();
    
private:


    

};

#endif /* APARTAMENTO_H */

