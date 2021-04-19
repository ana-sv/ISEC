// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Pescaria.h"

int Pescaria::count=0;

Pescaria::Pescaria() {
    count++;
    num = count;
    designacao = makeDesignation("pescaria", num);
    resistencia = 9;
    qtProdutosCria = 0;
    qtOuroCria = 1;
    conquistado = false;
   // cout << "---------->" << designacao << " construida! " << endl;
}

Pescaria::Pescaria(const Pescaria& orig) {
}

Pescaria::~Pescaria() {
}

void Pescaria::update(int turno) {

    if (turno > 6) // 2ºano
        qtProdutosCria = 4;

}