// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Cliente.h"
#include "Tarifario.h"


Cliente::Cliente(string n, unsigned int b, Tarifario *t)
: nome(n), bi(b), tarif(t) {
   
    horaInicio = -1;
}

Cliente::~Cliente() {
    delete tarif;
}

void Cliente::iniciaTreino(unsigned int hora){
    if( horaInicio != -1 )
        horaInicio=hora;
}

void Cliente::terminaTreino(unsigned int hora){
    if( horaInicio != -1 ){
        tarif->acrescentaTreino(hora-horaInicio);
        horaInicio = -1;
    }
}

unsigned int Cliente::paga(){
    return tarif->calculaPagamentoEApagaTreinos();
}

void Cliente::mudaTarifario( Tarifario * t){
    if( t != nullptr ){
        delete tarif;
        tarif = t;
    }
}


Cliente & Cliente::operator=( const Cliente &x ){
    
    //1.Testa auto-atribuicao para evitar trabalho desnecessario
    if( this == &x )
        return *this;
    
    //2.Liberta recursos atuais do objeto alvo de atribuicao
    // neste caso, só o objecto Tarifario
    delete tarif;
    
    //3.Cria copia dos recursos
    nome = x.nome;
    bi = x.bi;
    horaInicio = x.horaInicio;
    //3.1 No caso do Tarifario usar new nao é viavel porque não se sabe o tipo 
    // de Tarifario a duplica. Assim usamos a funcao duplica que é virtual em 
    // Tarifario mas está definida nas suas classes derivadas
    tarif = x.tarif->duplica;
    
    return *this;

}


Cliente::Cliente( const Cliente & x ){
    //1. Faz a pre-inicialização
    tarif = nullptr;
    
    //2. Usa o operador de atribuicao = 
    *this = x ; 
}



string Cliente::getAsString() const{
    ostringstream oss;
    oss << nome << " - BI: " << bi;
    return oss.str();
}