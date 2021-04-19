// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Mina.h"

int Mina::count=0;

Mina::Mina() {
    count++;
    num = count;
    designacao = makeDesignation("mina", num);
    resistencia = 5;
    qtProdutosCria = 0;
    qtOuroCria = 1;
    conquistado = false;
   // cout << "---------->" << designacao << " construida! " << endl;
}

Mina::Mina(const Mina& orig) {
}

Mina::~Mina() {
}


void Mina::update(int turno){   //rever 
    
    if (turno < 4){ // 1ºs 3 turnos de 1 ano
        qtOuroCria = 1;
    }
    else if (turno > 6 && turno < 10 ){ // 1ºs 3 turnos de 2 ano
        qtOuroCria = 1;
    }
    else{ 
        qtOuroCria = 2;
    } 
    
}