// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Ginasio.h"
#include "Cliente.h"

void Ginasio::avancaRelogio(unsigned int tempo){
    relogio += tempo;
}

bool Ginasio::acrescentaCliente( Cliente * c ){
    if( c == nullptr )
        return false;
    
    if( pesquisaClienteDadoBI( c->getBI() != -1 ))
        return false;
    
    clientes.push_back(c);
    return true;
}


unsigned int Ginasio::paga( unsigned int bi ){
    unsigned int ind= pequisaClienteDadoBI(bi);
    
    if( ind != -1 )
        return clientes[ind]->paga();
    
    return 0;
}

void Ginasio::entraClienteNoTreino( unsigned int bi){
    unsigned int ind= pequisaClienteDadoBI(bi);
    
    if ( ind != -1 ) return;  // cliente não encontrado 
    
    // 1. Verifica se o cliente ainda não está a treinar
    if ( clientes[ind].estaATreinar() == true )
        return;
    
    //2. Avisa os outros clientes a treinar que entrou na sala
    for( unsigned int i=0; i < clientes.size() ; i++){
        if( clientes[i]->estaATreinar() ){
         clientes[i]->reageEntrada(this);        
        }
    }
    
    //o cliente inicia o treino
    clientes[ind]->iniciaTreino(relogio);   
}

void Ginasio::saiClienteDoTreino( unsigned int bi){
    unsigned int ind= pequisaClienteDadoBI(bi);
    
    if ( ind != -1 ) return;  // cliente não encontrado 
    
    // 1.Não estava a treinar, foi engano 
    if (clientes[ind].estaATreinar() == false)
        return;

    //2.Tira da sala de treino
    clientes[ind]->terminaTreino(relogio);

    //4.Avisa os outros clientes a treinar que saiu um da sala
    for (unsigned int i = 0; i < clientes.size(); i++) {
        if (clientes[i]->estaATreinar()) {
            clientes[i]->reageSaida(this);
        }
    }
}


void Ginasio::removeCliente( unsigned int bi ){
    
    //1.Procura o cliente na base de dados
    unsigned int ind = pequisaClienteDadoBI(bi);
    
    //2. Encontou, manda-o sair do treio no
    saiClienteDoTreino(bi);
    
    //3.Paga conta antes de sair
    clientes[ind]->paga();
    
    //4.Apaga o Cliente - sendo que o enunciado diz que os 
    // Clientes pertencem ao ginasio
    delete clientes[ind];
    clientes.erase(clientes.begin() + ind );    
}


unsigned int Ginasio::getNumClientesATreinar()const{
    unsigned int n = 0;
    
    for ( unsigned int i =0 ; i < clientes.size(); i++){
        if( clientes[i]->estarATreinar() )
            n++;
    }
    return n;

}

unsigned int Ginasio::pesquisaClienteDadoBI( unsigned int bi ){

    for ( unsigned int i =0 ; i < clientes.size(); i++){
        if( clientes[i]->getBI() == bi ) 
            return i;
    }
    return -1;
    

}



Ginasio::Ginasio() {
     relogio = 0;
}


Ginasio::~Ginasio() {
    
    //Apaga as fichas. Nao é preciso fazer mais nada 
    for ( unsigned int i=0; i < clientes.size(); i++)
        delete clientes[i]; // porque o enunciado diz que os clientes pertencem ao ginasio
    
}


Ginasio::Ginasio(const Ginasio& x) {
    *this = x ; 
}

Ginasio & Ginasio::operator=( const Ginasio & x){
    
    //1. Testa a auto-atribuicao
    if ( this == &x ) return *this; 
        // se ja sao iguais retorna o mesmo
        // nao se libertam recursos do destino da distribuicao porque coincide com a origem
    
    //2.Apaga os recursos ja existemtes no "alvo" da atribuição
    for ( unsigned int i=0; i<clientes.size(); i++){
        delete clientes[i]; // apaga os objetos clientes 
    }
    clientes.clear(); // apaga os ponteiros para os objectos que ainda estavam no vetor 
    
    
    //3.Faz copia polimorfica dos clientes do Ginasio original 
    for ( unsigned int i=0; i<clientes.size(); i++)
        clientes.push_back(x.clientes[i]->duplica() ); //Seja lá qual for o tipo de clientes, duplica-se

    //4.So falta copiar o valor do relogio
    relogio = x.relogio;
    return *this;
}