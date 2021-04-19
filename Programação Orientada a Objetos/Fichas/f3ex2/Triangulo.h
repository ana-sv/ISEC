// Ana Videira | 2015012218 | 2020/2021

#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Ponto.h"

class Triangulo {
    Ponto p[3];
    string nome;
    
public:
    
    Triangulo();
    Triangulo(string n, Ponto a, Ponto b, Ponto c);
    ~Triangulo();
    
    const string getNome() const;
    Ponto getPonto(int x) const;
    
    void setPonto(const Ponto &np, int x);
    void setNome(const string &s);
    
    void getInfo(ostringstream &os) const;
};

#endif /* TRIANGULO_H */

