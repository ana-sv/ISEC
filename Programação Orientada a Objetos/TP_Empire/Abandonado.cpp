// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#include "Abandonado.h"

Abandonado::Abandonado() {
    designacao = "Recurso Abandonado";
    ident = "abandonado";
    descricao = "Fornece ao Imperio produtos ou ouro encontrados abandonados no Mundo.";
}

Abandonado::Abandonado(const Abandonado& orig) {
    
}

Abandonado::~Abandonado() {
}

bool Abandonado::eventAction(Imperio * imp, Mundo *m){
    
cout << endl << "Evento "<< designacao << " ativo ! " << endl;    
    
    if ( m->getAno()== 1 )
        imp->addArmazem(1);
    else
        imp->addCofre(1);   
    
    return true;
}
