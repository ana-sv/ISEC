// Ana Videira | 2015012218 | 2020/2021

#include "Ponto.h"

using namespace std;


int main(int argc, char** argv) {
    
    Ponto a(1,2);
    Ponto b(3,4);
    
    a.print();
    b.print();
    
    a.distance(b);
    
    Ponto c(5,6);
    string s;
    cout<< "\nc: " << c.infoTxt(s) << endl;
    
    Ponto d;
    d.print(); 

    return 0;
}

