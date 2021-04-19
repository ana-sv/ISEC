// Ana Videira | 2015012218 | 2020/2021

#ifndef CLUBE_H
#define CLUBE_H

#include "Pessoa.h"

class Clube {
    string nome;
    string descricao;
    string atividade; 
    vector <Pessoa> v; 
    
public:
    Clube(string n, string ativ);
    ~Clube();
    
    bool addPessoa( const Pessoa &pes); // ???


    
};

#endif /* CLUBE_H */

