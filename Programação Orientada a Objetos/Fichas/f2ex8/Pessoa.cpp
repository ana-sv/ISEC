// Ana Videira | 2015012218 | 2020/2021

#include "Pessoa.h"

Pessoa::Pessoa(const string &s, long b, long n): nome(s), bi(b),nif(n){
    cout << "Objeto Pessoa criado" << endl;
}

Pessoa::~Pessoa() {
    cout << "Objeto Pessoa destruido" << endl;
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

string Pessoa::print()const{
   ostringstream oss;
   oss << nome << "-" << bi << "-" << nif << endl;
   return oss.str();
}