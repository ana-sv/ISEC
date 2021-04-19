// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Montanha.h"

int Montanha::count=0; 

Montanha::Montanha() {
    count++;
    num = count;
    designacao = makeDesignation("montanha", num);
    resistencia = 6;
    qtProdutosCria = 0;
    qtOuroCria = 0;
    conquistado = false;
    // cout << "---------->" << designacao << " construida! " << endl;
    
}

Montanha::Montanha(const Montanha& orig) {
}

Montanha::~Montanha() {

}

void Montanha::update(int turno) {

   if ( turno > 2 )
     qtProdutosCria=1;       
}