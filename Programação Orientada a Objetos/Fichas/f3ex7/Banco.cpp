// Ana Videira | 2015012218 | 2020/2021
#include "Banco.h"

Banco::Banco( const string &s) {
    nome=s; 
    cout << "Banco construido!" << endl; 
}

Banco::~Banco() {
    cout << "Banco destruido!" << endl; 
}

void Banco::getInfo(ostringstream &oss) const{
   
    oss << "\nBanco: " << nome << endl; 
    for (int i=0; i<v.size(); i++){
        oss << "Conta " << i+1 << "\t";
       // oss << " Titular: " << v[i].getTitular->getNome() << endl;
        oss << "Saldo: " << v[i].getSaldo() << endl;
    }
}

void Banco::addConta( const Conta &c){
    v.push_back(c);
}