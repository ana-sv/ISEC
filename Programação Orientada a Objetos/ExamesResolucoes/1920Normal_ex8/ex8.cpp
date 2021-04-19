// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

//Exame 1920 - Época Normal - Exercicio 8


#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

class Planta{
    
private:
    int altura;
    int alturaMax;
    float percentagem;

public:
    virtual int crescimento(int distanciaSeparacao) const = 0;
    
};

class Parasita : public Planta {
    int crescimento(int distanciaSeparacao)const { };
};


class Hospedeira : public Planta {
private:
    int ditancia;
    Parasita pa;
public: 
int crescimento( int distanciaSeparacao )const {};    

};

class Plantacao{
private:
    vector <Planta*> plantas;
    void crescePlantas()const;
};


int main(int argc, char** argv) {

    return 0;
}

