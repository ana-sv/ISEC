// Ana Videira | 2015012218 | 2020/2021

// Banco & Conta » relacao de composicao 
// Pessoa & Conta » relacao de agregacao

#include "Banco.h"
#include "Conta.h"
#include "Pessoa.h"

int main(int argc, char** argv) {

    ostringstream oss;
    string s;
    
    Banco b("Bic");
    Pessoa p("Ana", 123, 456);
    Conta c(&p);

    b.addConta(c);
    b.getInfo(oss);
    cout << oss.str();

    p.getInfoPessoa(oss);
    cout << oss.str();

    c.getInfoConta(oss);
    cout << oss.str();

    return 0;
}

