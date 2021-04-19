// Ana Videira | 2015012218 | 2020/2021


#include <cstdlib>
#include <iostream>
#include <string>
#define TAM 10 

using namespace std;

struct tabela 
{
    int tab[TAM];
};

void init(tabela *a, int size, int valor);
void print(tabela a, int size);
int get(tabela a, int size, int pos);
void set(tabela *a, int size, int pos, int valor);
void print(tabela a, int size);

int & elementoEm(tabela &a, int pos) // devolve uma referência para um inteiro
{
    return a.tab[pos];
}


int main(int argc, char** argv) {
    tabela a;
 
    //alinea a
    init(&a, TAM, 5);

    //alinea b 
    print(a,TAM);
    cout << endl; 
    
    //alinea c 
    int x = get(a,TAM,4);
    set(&a,TAM,3,12);
    cout<<endl;
    
    //alinea d
    cout <<"Elemento na pos 7: " << elementoEm(a, 7); // imprime o valor dessa referência
    elementoEm(a, 3)=24; // altera a referencia para 24
    cout << endl;
    print(a, TAM);
    cout << endl; 
    cout << "Elemento na pos 3: " << elementoEm(a, 3); // imprime o valor dessa referência   
    
    return 0;
}



void init(tabela *a, int size, int valor){
    for(int i=0;i<size;i++)
    {
        a->tab[i]=valor;
    }
}


void print(tabela a, int size){
        for(int i=0; i<size; i++)
    {
        cout<<a.tab[i] << "\t";
    }

}

int get(tabela a, int size, int pos){
    if(pos>size)
        return 0; 
    return a.tab[pos];
}

void set(tabela *a, int size, int pos, int valor){
    if(pos>size)
        return ;
    
    a->tab[pos]=valor;
}
