// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

//Exame 1920 - Época Recurso - Exercicio 7


#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

class Fruta{
    
protected:
    static int conta;
    int id;
    float peso;
    
public: 
      Fruta(float pe): peso(pe){
         id = conta++;
    };
    float getPeso()const { return peso; };
    int getID()const { return id;};
    void setPeso( int p ){peso=p; };
    void setID( int i ){ id = i; };
    virtual float setCrescer()=0;
};

int Fruta::conta = 1;



class Limao: public Fruta{
    
public:
    Limao() : Fruta(150){};
    float setCrescer(){return peso = peso * 1.15;}
};



class Laranja: public Fruta {
    
public: 
  Laranja(): Fruta(100){};
  float setCrescer(){return peso = peso * 1.10;}
};

class Arvore {
    vector <Fruta*> frutas;

public:
    Arvore() = default;

    void nascer(Fruta *x) { frutas.push_back(x); }

    void cair(int x) {
        for (auto i = frutas.begin(); i != frutas.end(); i++)
            if ((*i)->getID() == x) {
                i = frutas.erase(i);
                return;
            }
    }

    void crescer() {
        for (int i = 0; i < frutas.size(); i++)
            frutas[i]->setCrescer();
    }

    int getTotal() const {
        return frutas.size();
    }

    Fruta* getFruto(int i) const {
        return frutas[i];
    }

};



//Mostra o id e peso de todos os frutos da Arvore

ostream & operator<<(ostream & out, Arvore & a) {
    for (int i = 0; i < a.getTotal(); i++)
        out << a.getFruto(i)->getID() << " " << a.getFruto(i)->getPeso() << endl;

    return out;
}


int main(int argc, char** argv) {
    
      Arvore a;
    a.nascer(new Laranja());
    a.nascer(new Laranja());
    a.nascer(new Limao());
    
    cout << a << endl;
    
    a.crescer();
    
    cout << a << endl;


    return 0;
}

