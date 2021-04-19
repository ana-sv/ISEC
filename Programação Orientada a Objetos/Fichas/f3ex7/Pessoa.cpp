// Ana Videira | 2015012218 | 2020/2021

#include "Pessoa.h"

Pessoa::Pessoa(const string &s, long b, long n): nome(s), bi(b),nif(n){
    cout << "Pessoa contruida!" << endl;
}

Pessoa::~Pessoa() {
    cout << "Pessoa destruida!" << endl;
}

void Pessoa::setNome(const string &n){
    nome = n;
}

string Pessoa::getNome()const{
    return nome;
}

long Pessoa::getBi()const{
    return bi;
}

long Pessoa::getNif()const{
    return nif;
}

void Pessoa::getInfoPessoa(ostringstream &oss)const{
   oss << nome << "-" << bi << "-" << nif << endl;
}