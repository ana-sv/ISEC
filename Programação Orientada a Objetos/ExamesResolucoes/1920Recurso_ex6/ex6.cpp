// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

//Exame 1920 - Época Recurso - Exercicio 6


#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;


class Excursao{
    
private: 
    string data;
    const string destino;
    int lotacao;
    vector <int> inscritos; 
    
public:
    
    // Criar objetos com todos os dados menos o de viajenates inscritos
    // Construtor 
    Excursao( string d, string des, int lo): data(d), destino(des), lotacao(lo){};

    // Inscrever viajantes dados os seus passaportes: excursao3 << 123 << 789 << 123; // o segundo 123 é ignorado
    // Operador <<
    Excursao &operator<<(int p) {

        for (auto i : inscritos) {
            if (p == i)
                return *this;
        }

        inscritos.push_back(p);
        return *this;
    }

    
    // Transferir passageiros de uma excursão para outra: excursao3 >> excursao2; 
    //Operador >>
    Excursao &operator>>(Excursao &e) {
        int lota = 0;

        for (int i = 0; i < e.lotacao && i < inscritos.size(); i++) {
            e.inscritos.push_back(inscritos[i]);
            lota++;
        }

        auto it = inscritos.begin();

        while (lota > 0) {
            it = inscritos.erase(it);
            lota--;
        }

        return *this;
    }

    
    //Atribuir excursões; excursao4 = excursao5;
    // Operador atribuicao
    Excursao &operator=(Excursao &p) {
        auto it = inscritos.begin();

        while (it != inscritos.end()) {
            it = inscritos.erase(it);
            it++;
        }

        data = p.data;
        lotacao = p.lotacao;

        p >> *this;

        return *this;

    }

    // Aceder a um viajante específico e poder por outro no seu lugar: excursao2[1] = 329
    //operador [ ]
    int &operator[](int i) {
        if (i > 0)
            return inscritos[i];
        else
            cout << "Erro";
    }

    
   // Saber quantos passageiros estão neste momento no autocarro: int a = excursao2 
    //operador de conversao
    
    operator int()const{
        int contador = 0;
        for(auto a : inscritos)
            contador++;
        return contador;
    }
    
    
    // Para testar resultados
     string getAsString()const{
        ostringstream os;
        os << "Data: " << data << " Destino: " << destino << " Lotacao: " << lotacao
        << " Inscritos: ";
        for(auto a : inscritos)
            os << " " << a;
            
        return os.str();
    }
    
};

// para usar o operador <<  para apresentar resultados 
ostream &operator<<(ostream &os, const Excursao &e){
    return os << e.getAsString();
};


int main(int argc, char** argv) {
    
     const string destino = "Porto";
    const string ola = "Lisboa";
    int a;
    
    Excursao excursao3("2020-10-01",destino,30);
    Excursao excursao2("2021-11-11",ola,30);
    
    excursao3 <<  123 << 456 << 789;
    
    cout << excursao3 << endl;
    
    a = excursao3;
    cout << "A: " << a << endl;
    
    cout << excursao3 << endl;
    //excursao3[2] = 666;
    
    //cout << excursao3 << endl;

    //excursao2 = excursao3;
    
    //cout << excursao2 << endl << excursao3;
    
    //excursao3 << 123 << 789 << 12 << 33 << 22 << 44 ;
    //cout << "Excursao 3: " << excursao3 << endl;
    
    
    //excursao3 >> excursao2;
    //cout << "Excursao 2: " << excursao2 << endl;
    
    //cout << "Excursao 3: " << excursao3 << endl;
    

    return 0;
}

