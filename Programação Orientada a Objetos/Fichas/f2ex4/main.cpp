// Ana Videira | 2015012218 | 2020/2021

#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;

class Caderno{
    string marca;
    string cor;
    int nFolhas;
    string tamanho;

public:

    Caderno(){};
    Caderno(string m, string c, int nf, string t){ 
        marca=m; 
        cor=c; 
        nFolhas=nf; 
        tamanho=t;
    };
 
    string getMarca() {return marca; };
    void setMarca(string m) { marca = m; };
    
    void print() const;

};


void Caderno::print() const{
    cout << "\nMarca: " << marca << endl;
    cout << "Cor: " << cor << endl;
    cout << "nFolhas: " << nFolhas << endl;
    cout << "Tamanho: " << tamanho << endl;
};


int main(int argc, char** argv) {

    Caderno a;
    Caderno b("Oxford","muilt", 100, "A4");
   
    a.print();
    a.setMarca("Ambar"); 
    a.print();
    
    b.print();
    b.getMarca();
    

    return 0;
}
