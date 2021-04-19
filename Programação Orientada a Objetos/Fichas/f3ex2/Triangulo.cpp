// Ana Videira | 2015012218 | 2020/2021

#include "Triangulo.h"
#include "Ponto.h"

Triangulo::Triangulo() {
    cout << " Triangulo Construido!" << endl;
}

Triangulo::Triangulo(string n, Ponto a, Ponto b, Ponto c){
    n=nome;
    p[0]=a;
    p[1]=b;
    p[2]=c;
    cout << " Triangulo " << nome << " construido!" << endl;
}

Triangulo::~Triangulo() {
    cout << " Triangulo " << nome << " destruido!" << endl;
}

const string Triangulo::getNome()const { return nome; }

Ponto Triangulo::getPonto(int x)const { return p[x]; }

void Triangulo::setPonto(const Ponto &np, int x){
    p[x]=np;
}

void Triangulo::setNome(const string &s){
    nome=s;
}

void Triangulo::getInfo(ostringstream &os) const
{
    os.str(""); // limpar os
    os << "Pontos do Triangulo " << nome << ": \n";
    os << "Ponto 0: (" << p[0].getX() << "," << p[0].getY() << ")\n";
    os << "Ponto 1: (" << p[1].getX() << "," << p[1].getY() << ")\n";
    os << "Ponto 2: (" << p[2].getX() << "," << p[2].getY() << ")\n";
}