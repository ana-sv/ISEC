// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef JOGO_H
#define JOGO_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <ctime>

using namespace std;
#include "Mundo.h"
#include "Imperio.h"
#include "BolsaValores.h"
#include "Snapshot.h"


class Jogo {
    
public:
    Jogo();
    Jogo(const Jogo& orig); // construtor por copia 
    virtual ~Jogo();
    
    string askCommand();
    void exitGame();
    
    string startMenu();
    void startGame();
    
    int goodLuck();
    int getLastLuck() const { return lastLuck; };
    void setLastLuck(int n){ lastLuck = n; };
    
    bool commands(string c);
    string commandHelp();
    string commandLista();
    string commandLista(string t);
    
    void faseZero();    // Configura Mundo
    bool loadTerritorios( string nomeFich );
        
    void faseUm();      // Conquistar
    bool commandConquista(string c);
    
    
    void faseDois();    // Recolher
        
    void faseTres();    // Compra militares & tecnologias

    void faseQuatro(); // Ocorrem eventos

    
    void faseCinco();
    bool loser();
    void updatePontuacao(Imperio * imp, Mundo * m);
    
    string printFinish();
    string printLoser();
    string printGamingAgain();

    
    //Registos
    void commandGrava(string s );
    void commandAtiva(string s);
    void commandApaga(string s);    
    
    //DEBUG
    void commandToma( string type, string word );
    void commandModifica( string type, int n );
    void commandFEvento( string type );
    
    

private:
  
    Imperio *imp;
    Mundo *m;
    int fase;
    static int lastLuck;
    vector < Snapshot * > vsnap;

};

#endif /* JOGO_H */

