// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Castelo.h"

int Castelo::count=0;

Castelo::Castelo() {
    count++;
    num = count;
    designacao = makeDesignation("castelo", num);
    resistencia = 7;
    qtProdutosCria = 0;
    qtOuroCria = 1;
    conquistado = false;
  //  cout << "---------->" << designacao << " construida! " << endl;
}
   

Castelo::Castelo(const Castelo& orig) {
}

Castelo::~Castelo() {
}

void Castelo::update(int turno){
    
    if (turno < 3){ // 1ºs 2 turnos de 1 ano
        qtOuroCria = 1;
    }
    else if (turno > 6 && turno < 9 ){ // 1ºs 2 turnos de 2 ano
        qtOuroCria = 1;
    }
    else{ 
        qtOuroCria = 3;
    } 

}
