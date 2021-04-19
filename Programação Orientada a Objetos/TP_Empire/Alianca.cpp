// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#include "Alianca.h"

Alianca::Alianca() {
    designacao = "Alianca Diplomatica";
    ident = "alianca";
    descricao = "Acordo com outro imperio, aumenta 1 unidade de Forca Militar";
}

Alianca::Alianca(const Alianca& orig) {

}

Alianca::~Alianca() {
}

bool Alianca::eventAction(Imperio * imp, Mundo * m) {

    cout << endl << "Evento " << designacao << " ativo ! " << endl;
    imp->increaseFmilitar();

}