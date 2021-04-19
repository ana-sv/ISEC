// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Planicie.h"
#include "Mundo.h"

int Planicie::count = 0;

Planicie::Planicie() {
    count++;
    num = count;
    designacao = makeDesignation("planicie", num);
    resistencia = 5;
    qtProdutosCria = 1;
    qtOuroCria = 1;
    conquistado = false;
   // cout << "---------->" << designacao << " construida! " << endl;
}

Planicie::Planicie(const Planicie& orig) {
    //cout << "---------->Planicie Construida! " << endl;
}

Planicie::~Planicie() {
    //cout << "---------->Planicie Destruida! " << endl;
}

void Planicie::update(int turno) {

    if (turno > 6) // 2ºano
        qtProdutosCria = 2;

}