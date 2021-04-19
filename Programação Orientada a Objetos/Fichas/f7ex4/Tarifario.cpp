// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Tarifario.h"

Tarifario::Tarifario() {  //construtor 
    treinos = nulltpr; 
    quantos = 0;
}


Tarifario::~Tarifario() { //destrutor 
    delete [] treinos;
}


Tarifario::Tarifario(const Tarifario& x) { // construtor por copia 
    treinos = nullptr;
    quantos = 0 ;
    *this = x;  // uso do operador atribuição = 
}

Tarifario & Tarifario::operator=( const Tarifario & x){
    
    //1. Testa operador atribuicao para evitar trabalho desnecessario os incoerencia 
    if( this == & x ) // se na memoria dinamica já são o mesmo 
        return *this;   // entao ja sao iguais

    //2. Devolve os recursos ocupados pelo objecto alvo da atribuição , "prepara limpado objeto alvo"
    delete[] treinos;
    treinos nullptr;
    quantos = 0;
    
    //3. Se os outro objectos também tem 0 treinos, entao tambem já sao iguais
    if(x.treinos == nullptr) return *this;
    
    //4. Criar recursos iguais (copiar) aos do outro objecto
        //4.1 Alocar matriz dinamica para tantos treinos como os do outro objecto
        //4.2 Copiar dos dados: o conteudo da matriz e restantes membros
    treinos = new unsigned int [x.quantos];
    quantos = x.quantos;
    for(unsigned int i=0; i<quantos ; i++)
        treinos[i] = x.treinos[i];
    return *this;
    
}



void Tarifario::acrescentaTreino(unsigned int t){
    unsigned int * aux = new unsigned int [quantos + 1];
    
    if( aux == nullptr ) 
        return;
    
    for ( unsigned int i=0; i< quantos; i++)
        aux[i]= treinos[i];
   
    aux[quantos]= t;
    quantos ++;
    delete[] treinos;
    treinos = aux;  
}

unsigned int Tarifario::calculaPagamentoEApagaTreinos(){
    unsigned int conta = calculaPagamento();
    
    delete[] treinos;
    treinos = nullptr;
    quantos = 0;
    
    return conta;
}

unsigned int Tarifario::getTreino( unsigned int i) const{
    if ( i<0 || i>quantos )
        return 0;
    
    return treinos[i];
}

unsigned int Tarifario::getNumTreinos() const { return quantos; }