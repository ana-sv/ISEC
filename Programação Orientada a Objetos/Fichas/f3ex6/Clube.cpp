// Ana Videira | 2015012218 | 2020/2021

// Pessoa e Clube têm uma relação de agregação

#include "Clube.h"

Clube::Clube(string n, string ativ): n(nome), ativ(atividade) {
    cout << "Clube construido!" << endl; 
}

Clube::~Clube() {
    cout << "Clube destruido!" << endl; 
}

bool Clube::addPessoa( const Pessoa &pes){
    v.push_back(pes);

}
