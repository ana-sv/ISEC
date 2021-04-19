// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#ifndef EVENTO_H
#define EVENTO_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <ctime>

class Imperio;
class Mundo;

using namespace std;

class Evento {
    
public:
    Evento();
    Evento(const Evento& orig);
    virtual ~Evento();
    
    string getDesignacao(){ return designacao; };
    string getIdent(){ return ident; };
    
    string show();
    virtual bool eventAction(Imperio * imp, Mundo * m);
    
    virtual Evento *clone(){ return new Evento(*this); };
    
protected:
    string designacao;
    string ident;
    string descricao;

};

#endif /* EVENTO_H */

