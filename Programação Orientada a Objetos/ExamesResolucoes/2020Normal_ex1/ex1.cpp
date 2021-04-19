// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

//Exame 2020 - Época Normal - Parte 1 - Exercicio 1

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


class Erro{ 
    
public:
    virtual string what()const{
        return "carvao;";
    }
};

class ErroDeriv : public Erro {
public:
    string what()const override{
        return "marmore;";
    }
};

void testar(){
    throw ErroDeriv();
    cout << "granito;"; 
};


int main(int argc, char** argv) {
    
    try{
        testar();
    }
    catch (Erro & e){
        cout << e.what();    
    }
    catch(string e){
        cout << "basalto;";
    }
    cout << "fim;\n";     
    

    return 0;
};


// Resultado:
// marmore;fim;


// testar()  --> throw ErroDeriv(); 
// --> na Classe ErroDeriv , what() overrides what() da classe base Erro --> return marmore
// --> cout marmore 
// --> termina o try/catch 
// --> cout fim 


