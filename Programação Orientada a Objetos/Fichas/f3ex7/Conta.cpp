// Ana Videira | 2015012218 | 2020/2021

#include "Conta.h"

Conta::Conta(Pessoa *p): titular(p) {
    saldo=0;
    cout << "Conta construida!" << endl; 
}

Conta::~Conta() {
    cout << "Conta destruida!" << endl; 
}

void Conta::getInfoConta( ostringstream &oss)const{
    oss << "Conta com titular: " << titular->getNome() << "\t";
    oss << "-> Saldo: " << saldo << endl;
}

Pessoa * Conta::getTitular() const{
    return titular;
}

int Conta::getSaldo() const{
    return saldo;
}

int Conta::setSaldo( int s){
    saldo=s;
}