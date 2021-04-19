// Ana Videira | 2015012218 | 2020/2021

#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Ponto.h"

class Rectangulo {
    Ponto cse; //ponto no canto superior esquerdo 
    int altura;
    int largura;    
public:
    Rectangulo(const Ponto &p, int alt, int larg);
    ~Rectangulo();
    
    const Ponto getCse() const; 
    int getAlt() const;
    int getLarg() const;
    
    void moveRectangulo(const Ponto &novo);
    int area() const;
    
    void getInfo(ostringstream &os) const;


};

#endif /* RECTANGULO_H */

