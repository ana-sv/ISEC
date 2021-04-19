// Ana Videira | 2015012218 | 2020/2021

// a pessoa nao pertence ao clube - relacao agregação

// contrutor por cópia tem que ser feito 

#include <cstdlib>

using namespace std;


int main(int argc, char** argv) {


    Pessoa a("Ana", 123,456), b("Rita",789,101112); // de acordo com o que estiver na classe Pessoa
    Clube c(50);
    c.setMembroDoClube(&a, 0); // Pessoa a passa a pertencer ser membro do clube
    c.setMembrodoClube(&b, 1); // Idem Pessoa b
    return 0;

}

