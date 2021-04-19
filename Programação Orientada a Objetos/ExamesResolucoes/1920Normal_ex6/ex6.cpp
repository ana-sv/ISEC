// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

//Exame 1920 - Época Normal - Exercicio 6

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Bilhete {
public:

    //Criar objectos indicando todos os dados inclusive um conjunto inicial de malas 

    Bilhete(string p, int pa, string &co, vector<int> ma)
    : passageiro(p), passaporte(pa), companhia(co), id_malas(ma) { }

    //  Bilhete(const Bilhete& orig);
    // virtual ~Bilhete();


    // atribuir objectos -> operador atribuicao ( = ) 

    Bilhete &operator=(const Bilhete &b) {
        passageiro = b.passageiro;
        passaporte = b.passaporte;

        for (size_t i = 0; i < b.id_malas.size(); i++)
            id_malas.push_back(b.id_malas[i]);

        return *this;

    }


    //Acrescentar bagagens ao bilhete 
    //(representadas pelos seus id e sem repetir)
    // bilhete << 123 << 789 << 123;   -> ignora 123

    Bilhete &operator<<(int p) {

        for (auto i : id_malas) {

            if (p == id_malas[i])
                return *this;
        }

        id_malas.push_back(p);

        return *this;
    }




    // Remover todas as bagagens com id superior a um indicado
    // (bilhete2 -=40 ) -=35;

    Bilhete &operator-=(int id) {

        auto it = id_malas.begin();

        while (it != id_malas.end()) {

            if (id >= *it)
                it = id_malas.erase(it);
            else
                it++;

        }

        return *this;
    }

    
    string getAsString()const {
        ostringstream os;

        os << "Passageiro: " << passageiro << " Passaporte: " << passaporte << " Companhia: "
                << companhia << " Malas: ";
        for (auto i : id_malas)
            os << " " << i;

        return os.str();
    }


private:

    string passageiro;
    int passaporte;
    string & companhia;
    vector <int> id_malas;

};



// Mostrar Conteudo no ecrã da forma 
// cout << "\nPassageiro 1: " << bilhete1 << "Passageiro 2 << bilhete 2;

ostream &operator<<(ostream &os, const Bilhete &b) {
    return os << b.getAsString();
}


int main(int argc, char** argv) {

    string ola = "ola";

    Bilhete bi("Bruno", 123, ola,{1, 30, 3, 40, 5});
    Bilhete a("Rafael", 123, ola,{3, 4});

    cout << bi << endl;

    bi << 123 << 789 << 123;

    (bi -= 20) -= 30;

    cout << bi;

    return 0;
}

