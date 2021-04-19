// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

// Herança e Polimorfismo 

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>

#include "Imovel.h"
#include "Loja.h"

using namespace std;

int main(int argc, char** argv) {
    
    Loja l1(4);
    Loja l2(8);
    
    cout << endl << l1 << endl;
    cout << l2 << endl << endl;

    return 0;
}

