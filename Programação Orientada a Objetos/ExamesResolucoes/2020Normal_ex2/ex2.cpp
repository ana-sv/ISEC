// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

//Exame 2020 - Época Normal - Parte 1 - Exercicio 2

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
/*
 Considere uma classe que armazena mensagens de números (conjunto de números).
 Pretende-se que os objectos desta classe facilitem o seu uso, podendo ser usados
 de forma que vem exemplificada abaixo. O armazenamento dos numeros está sujeito a 
 algumas regras tal como notado nos comentários do exemplo. Implemente a classe 
 cumprindo os requisitos e fazendo com que o código abaixo funcione. 
 
 
 Telex a -> Fica sem numero nenhum
 Telex b({10,30,20,40}); -> Fica com os quatros valores indicados.
                         -> É compatível com qualquer numero de valores.
                   
 a << 30 << 50 << 50; -> a fica com 30 e 50 (não repete)
 
 if (a!=b) { ... } -> a e b só seriam iguais se tiverem os mesmos valores, pode ser por ordem diferente
 
 b -= 40; -> b fica sem o valor 40 (caso o tenha)
 
 cout << "b agora tem" << (int) b << "valores"; -> b agora tem 3 valore 
 a << b;  -> tranfere os valore de b para a que ainda não existissem em a 
          -> sendo removidos de b aqueles que foram transferidos
 
 */


class Telex {
    

private:
    vector <int> vnumeros;

public:

    Telex() {
        cout << "\n--> Telex construido s/ argumentos\n";
    };

    Telex(vector <int> v) : vnumeros(v) {
        cout << "\n--> Telex construido c/ argumentos\n";
    };

    
    Telex &operator<<(int n){
        cout << "\n[ OPERATOR << ]" << endl;
        //  a << 30 << 50 << 50; -> a fica com 30 e 50 (não repete)
        
        auto it = vnumeros.begin();
        
        while (it != vnumeros.end() ){
            
            if( n == *it)
                return *this;       
            it++;
        }
        
        vnumeros.push_back(n);
        return *this;
    
    };
    
    
   Telex &operator!=( Telex t){
          cout << "\n[ OPERATOR !=  ] " << endl;
          // b -= 40; -> b fica sem o valor 40 (caso o tenha)
    
    
    };
    
    
    
    
    Telex &operator-=(int n) {
        cout << "\n[ OPERATOR -= ] " << endl;
        //  b -= 40; -> b fica sem o valor 40 (caso o tenha)

        auto it = vnumeros.begin();

        while (it != vnumeros.end()) {

            if (n >= *it){
                it = vnumeros.erase(it);
                return *this;
            }
            else
                it++;
        }
        return *this;
    }
    
    

    Telex &operator<<(Telex t) {
        cout << "\n[ OPERATOR <<  ] " << endl;
        
    }




        


};



int main(int argc, char** argv) {

    Telex a;
    Telex b({10, 30, 20, 40});
    
    a << 30 << 50 << 50;
    
 //   if( a != b )
  //      cout << "Sao diferentes! ";
 
    
    b -= 40;
    
   //???  cout << "b agora tem" << (int) b << valores; 
    
    cout << "\n[ THE END ]\n" << endl;
    
}





