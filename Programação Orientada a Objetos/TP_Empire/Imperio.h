// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef IMPERIO_H
#define IMPERIO_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

#include "Mundo.h"

#include "Tecnologia.h"
#include "BancoCentral.h"
#include "BolsaValores.h"
#include "DefesasTerritoriais.h"
#include "DronesMilitares.h"
#include "MisseisTeleguiados.h"

class Territorio;
class BolsaValores;

class Imperio {
    
public:
    Imperio();
    
    Imperio(const Imperio& orig);
    
    virtual ~Imperio();
    
    Imperio *clone(){ return new Imperio(*this); };
    
    void setArmazem(int n) { armazem = n; };
    void setMaxArmazem(int n) { maxArmazem = n; };
    void setCofre(int n) { cofre = n; };
    void setMaxCofre(int n) { maxCofre = n; };
    void setFmilitar(int n) { fMilitar = n; };
    void setMaxMilitar(int n) { maxFmilitar = n; };
    void setPontuacao(int n) { pontuacao = n; };
    
    int getArmazem() const { return armazem; };
    int getMaxArmazem() const { return maxArmazem; };
    int getCofre() const { return cofre; };
    int getMaxCofre() const { return maxCofre; };
    int getFmilitar() const { return fMilitar; };
    int getMaxMilitar() const { return maxFmilitar; };
    int getPontuacao() const { return pontuacao; };  
    
    bool addArmazem( int n ); 
    bool addCofre( int n );
    
    void decreaseFmilitar();
    void increaseFmilitar();
    
    bool payOuro(int custo);
    bool payProd(int custo);
    
    
    string show(Mundo * m) const;
    
    void war(Territorio * t, Mundo * m, int luck);
    int checkConquered( Mundo * m );
    
    void collect(Mundo * m);

    Tecnologia * getTecnologia(string ident);
    BolsaValores * findBolsaValores();
    
    void shopMilitar();
    
    bool addTech(string t, Imperio * i);
    void shopTech(string t,Imperio * i);
    string showTech() const ;
    
    vector <Tecnologia *> getVector(){ return vtec; };
    
private:
    int pontuacao;
    int armazem;
    int maxArmazem;
    int cofre;
    int maxCofre;
    int fMilitar; 
    int maxFmilitar;
    vector < Tecnologia *> vtec; 
    
};

#endif /* IMPERIO_H */

