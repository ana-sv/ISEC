// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

//Exame 2020 - Época Normal - Parte 1 - Exercicio 3

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <memory>

using namespace std;


class Item{
    string msg;
public:
    Item(const string & s) :msg(s) {
        cout << "Const " << msg << "; " << endl;
    }
    ~Item(){
        cout << "Dest " << msg << "; " << endl;
    }
};

void f(){
    unique_ptr<Item> a = make_unique<Item>("Girassol");
    Item * p = new Item("Magnolia");
}

int main(int argc, char** argv) {
    f();
    return 0;
}

/*
 
Resultado:
 
Const Girassol; 
Const Magnolia; 
Dest Girassol; 

 
 */
