// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Refugio.h"

int Refugio::count=0;

Refugio::Refugio() {
    count++;
    num = count;
    designacao = makeDesignation("refugioPiratas", num);
    resistencia = 9;
    qtProdutosCria = 0;
    qtOuroCria = 1;
    conquistado = false;
   // cout << "---------->" << designacao << " construida! " << endl;
}

Refugio::Refugio(const Refugio& orig) {
}

Refugio::~Refugio() {
}

void Refugio::update(int turno) {

  // 

}