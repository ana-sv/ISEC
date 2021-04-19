// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Duna.h"

int Duna::count=0;

Duna::Duna() {
    count++;
    num = count;
    designacao = makeDesignation("duna", num);
    resistencia = 4;
    qtProdutosCria = 1;
    qtOuroCria = 0;
    conquistado = false;
    //cout << "---------->" << designacao << " construida! " << endl;
}

Duna::Duna(const Duna& orig) {
}

Duna::~Duna() {
}

void Duna::update(int turno){
    
    //
}