// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "DefesasTerritoriais.h"

DefesasTerritoriais::DefesasTerritoriais() {
    designacao = "Defesas Territoriais";
    ident = "defesas";
    custo = 4;
    incDefesa=1;   
    accao = "[ * ] Imperio pode agora incrementar a defesa de um territorio em caso de algum Evento! ";    
}

DefesasTerritoriais::DefesasTerritoriais(const DefesasTerritoriais& orig) {
}

DefesasTerritoriais::~DefesasTerritoriais() {
}

  
void DefesasTerritoriais::techDefense(Territorio* t) {
    
    
   int n = t->getResistencia();
    
    n += incDefesa;
    
    t->setResistencia(n);
    
}