// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef MUNDO_H
#define MUNDO_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <ctime>

using namespace std;

#include "Territorio.h"
#include "Planicie.h"
#include "Montanha.h"
#include "Fortaleza.h"
#include "Mina.h"
#include "Duna.h"
#include "Castelo.h"
#include "Refugio.h"
#include "Pescaria.h"
#include "Evento.h"
#include "Abandonado.h"
#include "Invasao.h"
#include "Alianca.h"

class Jogo;

class Mundo {
    
public:
    
    Mundo();
    Mundo(const Mundo& orig);
    virtual ~Mundo();
    
   virtual Mundo *clone(){ return new Mundo(*this); };
    
    friend class Imperio; 
    
    int getAno() const; 
    int getTurno() const { return turno; };
    void setTurno(int t) { turno = t; }
    void incTurno() { turno++; }; 
    
    vector <Territorio *> getVector(){ return vt; };
    
    bool addTerritorio(string nome, int n);

    string show() const;
    Territorio* getTerritorio(string d);

    void updateMundo();
    bool addEvents();
    string showEvents();

    void chooseEvent();
    Evento * findEvent( string s );
    void setEvent( Evento * e ){ event = e; };
    Evento * getEvent() { return event; };
    
    
 
    
protected: 
    vector < Territorio *> vt;
    vector < Evento *> ve;

private:    
    int turno;
    static Evento * event;

};

#endif /* MUNDO_H */

