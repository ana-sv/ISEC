// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Tecnologia.h"

Tecnologia::Tecnologia() {
    designacao = "";
    ident = "";
    accao = " ";
    custo = 0;
}

Tecnologia::Tecnologia(const Tecnologia& orig) {
    designacao = orig.designacao;
    ident = orig.ident;
    accao = orig.accao;
    custo = orig.custo;
    
}

Tecnologia::~Tecnologia() {
}

string Tecnologia::show() {
    ostringstream os;
    os.str("");

    os << designacao << " - " << accao << endl;

    return os.str();

}

string Tecnologia::showPrice() {
    ostringstream os;
    os.str("");

    os << designacao << " - custo -  " << custo << endl;

    return os.str();

}
