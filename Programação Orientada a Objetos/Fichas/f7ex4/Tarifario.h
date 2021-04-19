// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef TARIFARIO_H
#define TARIFARIO_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


class Tarifario {
    
public:
    Tarifario(); // construtor 
    virtual ~Tarifario(); // destrutor 
    
    Tarifario(const Tarifario& x); // construtor por copia
    Tarifario & operator=(const Tarifario & x);
    virtual Tarifario * duplica()const = 0; // Nao se pode construir um Tarifario ainda porque e classe abstracta 

    void acrescentaTreino(unsigned int t);
    unsigned int calculaPagamentoEApagaTreinos();

    unsigned int getNumTreinos() const;
    unsigned int getTreino(unsigned int i) const;


protected:
    apagaTreiros();
    
private:
    unsigned int *treinos; // guarda conjunto de inteiros, alternativa a usar um vetor
    unsigned int quantos;
    virtual unsigned int calculaPagamento()const = 0; // funcao virtual a implementar pelas classes derivadas;

    

};

#endif /* TARIFARIO_H */

