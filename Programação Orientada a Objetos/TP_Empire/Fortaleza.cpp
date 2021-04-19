// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#include "Fortaleza.h"

int Fortaleza::count=0;

Fortaleza::Fortaleza() {
    count++;
    num = count;
    designacao = makeDesignation("fortaleza", num);
    resistencia = 8;
    qtProdutosCria = 0;
    qtOuroCria = 0;
    conquistado = false;
     //cout << "---------->" << designacao << " construida! " << endl;
}

Fortaleza::Fortaleza(const Fortaleza& orig) {
}

Fortaleza::~Fortaleza() {
}


void Fortaleza::update(int turno) {

   // sem update em produtos/ouro
    

}
