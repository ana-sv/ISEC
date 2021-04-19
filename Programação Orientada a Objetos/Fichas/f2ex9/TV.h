// Ana Videira | 2015012218 | 2020/2021

#ifndef TV_H
#define TV_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <initializer_list>

using namespace std;

class TV {
    vector <string> canais;
    bool on; 
    int volume;
    int atual;  
    
public:
    TV(initializer_list <string> s);
    void ligar(); 
    void desligar();
    void aumentarVolume();
    void diminuirVolume();
    void mudarCanal(int n);
    void gerarStream(ostringstream &s) const ;

};

#endif /* TV_H */

