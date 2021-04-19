// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "BolsaValores.h"


BolsaValores::BolsaValores() {
    designacao = "Bolsa de Valores ";
    ident = "bolsa";
    custo = 2;
    accao = "[ * ] Imperio tem agora acesso a Bolsa de Valores. Pode agora trocar ouro por produtos e vice-versa. ";
}

BolsaValores::BolsaValores(const BolsaValores& orig) {

}

BolsaValores::~BolsaValores() {
}


bool BolsaValores::techBolsaValores(Imperio * imp, string s ){
    
    cout << " _________ B o l s a  d e  V a l o r e s _________ " << endl;
    
    if (s == "maisouro") {

        if (imp->payProd(2) == true) {
            imp->setArmazem(imp->getArmazem() + 1);
            cout << "[ * ] Trocou 2un de Produtos por 1un de Ouro!" << endl;
        } else {
            cout << "[ ! ] Troca invalida!" << endl;
        }
        
    } else if (s == "maisprod") {

        if (imp->payOuro(2) == true) {
            imp->setCofre(imp->getCofre() + 1);
            cout << "[ * ] Trocou 2un de Ouro por 1un de Produtos!" << endl;
        } else {
            cout << "[ ! ] Troca invalida!" << endl;
        }
    }
    else{
        cout << "[ ! ] Accao invalida ! " << endl;
    }


}