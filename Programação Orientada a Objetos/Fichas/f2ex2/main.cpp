// Ana Videira | 2015012218 | 2020/2021

#include <cstdlib>
#include <iostream>
#include <string>

#define TAM 10

using namespace std;

class Tabela {
    int tab[TAM];
    
public:
    Tabela();           // construtor;
    Tabela(int v);      // construtor;
    void init(int v);
    void print() const;
    int & elementoEm(int pos);
};

Tabela::Tabela(){      // construtor que inicia objetos tabela a 0 
    for(int i=0; i<TAM; i++)
        tab[i]=0;
}

Tabela::Tabela(int v){      // contrutor que inicia objetos tabela com um valor especifico que vai sendo incrementado a cada posição
    for(int i=0; i<TAM; i++)
        tab[i]=v++;
}

void Tabela::init(int v ){   // o mesmo que a cima
    for(auto &x : tab)          
        x=v++;
}

void Tabela::print() const {  // não está autorizado a alterar os dados da variável por causa de const 
    for(auto x : tab)
        cout << x << " ";
    cout << endl;
}

int & Tabela::elementoEm(int pos)
{
    return tab[pos];
}

int main(int argc, char** argv) {
    
    Tabela a;
    cout<< " a : ";
    a.print();
    
    a.init(4);
    cout<< " a init(4): ";
    a.print();
      
    Tabela b(4);
    cout<< " b :      ";
    b.print();
    

    cout << a.elementoEm(2) << endl;
    a.elementoEm(2) = 154;
    cout << a.elementoEm(2) << endl;


    return 0;
}
