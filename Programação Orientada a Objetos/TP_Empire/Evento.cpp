// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#include "Evento.h"

Evento::Evento() {
    designacao = "Nada Acontece";
    ident = "nada";
    descricao = " Nao acontece nada, podem todos dormir descansados ";
}

Evento::Evento(const Evento& orig) {
    designacao = orig.designacao;
    ident = orig.ident;
    descricao = orig.descricao;
}

Evento::~Evento() {
}

string Evento::show(){
    ostringstream os;
    os.str("");
    
    os << designacao << " - " << descricao << endl;
    
    return os.str();
}


bool Evento::eventAction(Imperio * imp, Mundo * m){
    
     cout << endl << "Evento "<< designacao << " ativo ! " << endl;
     cout << descricao << endl;


}