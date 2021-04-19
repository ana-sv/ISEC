// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef SNAPSHOT_H
#define SNAPSHOT_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <ctime>

#include "Mundo.h"
#include "Imperio.h"


using namespace std;

class Snapshot {
    
public:
    friend class Jogo;
    
    Snapshot( string nome);
    Snapshot(const Snapshot& orig);
    virtual ~Snapshot();
        
    void setImperio( Imperio i ){ imp = i; };
    void setMundo( Mundo  mun ){ m = mun; };
    void setLastLuck( int n){ lastLuck = n; };
    
    string getIdent(){ return ident; };
    Imperio getImperio(){ return imp; };
    Mundo getMundo(){ return m; };
    int getLastLuck(){ return lastLuck; };
    
    string show();
    
    
private:
    string ident;
    Imperio imp;
    Mundo m;
    int lastLuck;

};

#endif /* SNAPSHOT_H */

