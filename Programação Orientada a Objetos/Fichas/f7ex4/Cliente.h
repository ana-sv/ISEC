// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#ifndef CLIENTE_H
#define CLIENTE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Tarifario;
class Ginasio;

class Cliente {
    
public:
    
    Cliente(string n, unsigned int b, Tarifario * t);
    virtual ~Cliente();
    
    void iniciaTreino(unsigned int hora);
    void terminaTreino(unsigned int hora);
    unsigned int paga();
    
    //funcoes virtuais puras
    virtual void reageEntrada(Ginasio * g) = 0;
    virtual void reageSaida(Ginasio * g) = 0;
    
    void mudaTarifario(Tarifario * t);
    
    Cliente & operador= ( const Cliente &x );
    
    Cliente( const Cliente &x);
    
    virtual Cliente * duplica()const = 0; // virtual pura, cliente é classe Abstracta
    virtual string getAsString() const;     
    
    unsigned int getBI(){ return bi; };
    bool estaATreinar(){ return horaInicio != -1;};
    
private:
    string nome;
    unsigned int bi;
    Tarifario * tarif;
    unsigned int horaInicio; // -1 se o cliente nao estiver a treinar 

    // Se fosse proibido copiar e atribuir obejtctos da classe Cliente
    // Cliente( const Cliente & x) = delete;
    // Cliente & operator=(const Cliente & x ) = delete;

};

#endif /* CLIENTE_H */

