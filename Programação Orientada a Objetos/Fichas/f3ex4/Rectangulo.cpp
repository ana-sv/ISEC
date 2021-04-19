// Ana Videira | 2015012218 | 2020/2021

#include "Rectangulo.h"

Rectangulo::Rectangulo(const Ponto &p, int alt, int larg) {
    cse=p;
    altura=alt;
    largura=larg;
    cout << "Rectangulo Construido" << endl;
}

Rectangulo::~Rectangulo() { 
    cout << "Rectangulo Destruido" << endl;
}

Ponto const Rectangulo::getCse() const { return cse; }

int Rectangulo::getAlt() const { return altura; }

int Rectangulo::getLarg() const { return largura; }

void Rectangulo::moveRectangulo( const Ponto &novo){
    cse=novo;
}

int Rectangulo::area() const{
    return altura*largura;
}

void Rectangulo::getInfo(ostringstream &os) const
{
    os.str("");  // limpar 
    os << "Info Rectangulo  \n";
    os << "Ponto Cse: (" << cse.getX() << "," << cse.getY() << ")" << endl;
    os << "Altura: " << altura << endl;
    os << "Largura: " << largura << endl;
    os << "Area: " << area() << endl;   
}

