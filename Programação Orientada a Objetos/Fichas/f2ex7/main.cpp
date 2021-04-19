// Ana Videira | 2015012218 | 2020/2021

#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>


using namespace std;


class MSG{
    char letra;
    int numero;
    static int aux;
    
public:
    MSG();          //construtor por omissao
    MSG(char l);    // construtor 
    
    ~MSG();         // destrutor 

};

int MSG::aux=1;

MSG::MSG(){
    letra = 'x';
    numero = aux++;
    cout << "Criado: \t letra:" << letra << " - numero:" << numero << endl;

}

MSG::MSG(char l) {
    letra = l;
    numero = aux++;
    cout << "Criado: \t letra:" << letra << " - numero:" << numero << endl;
}


MSG::~MSG(){
    cout << "Terminado: \t letra:" << letra << " - numero:" << numero << endl;
}



int main(int argc, char** argv) {

    MSG a('a');
    MSG b;

    MSG &c = b; // nao cria uma variavel nova, assim &c é a mesma coisa que b 

    MSG d = c; // construtor por cópia

  //  a = b; // atribuição direta

   //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // fica à espera de um \n
    
    return 0;
}

