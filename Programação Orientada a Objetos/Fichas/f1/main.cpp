// Ana Videira | 2015012218 | 2020/2021

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


void imprime(string texto){
    cout<<texto<<endl;
};

void imprime(string texto, int num){
    cout<<texto<<num<<endl;
};

void imprime(int num, string texto){
    cout<<num<<texto<<endl;
};

int soma(){
    return 1;
}

int soma(int a){
    return 1+a;
}

int soma(int a , int b){
    return 1+a+b;
}

int soma(int a, int b, int c){
    return 1+a+b+c;
}

int troca( int *a, int *b){
    int c;
    
    c= *a;
    *a = *b;
    *b = c;

}

string inverte(string s) {

    int i, j;
    char aux;

    for (i = 0, j = s.size() - 1; i < j; i++, j--) {
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }


    return s;
}


int main(int argc, char** argv) {
    
    

    // ex2 //////////////////////////////////
    /*
    char nome[100];
    int idade;
    cin.getline(nome, 99);
    do
    {
        cin.ignore(cin.rdbuf()->in_avail());
        cin.clear();
        cout<< "Idade: ";
        cin >> idade;
    } while(cin.fail());
    
    cout<< "Lido: " << nome << "\t"<< idade << "\n";
    */
    
    
    // ex3 //////////////////////////////////
    /*
    string nome;
    
    do
    {
        cout << "Nome: ";
        getline(cin, nome);
        
    }while(nome=="");
    
    int idade;
    do
    {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Idade: ";
        cin>> idade;
        if(cin.fail() || idade<0)
        {
            cout<< "Idade Invalida";
        }
    }while(cin.fail() || idade<0);
    
    cout<<"Numero de letras:";
    cout<<nome.length()<<"\n";
    
    if(nome=="ana")
    {
        cout<< "Tem o nome certo!\n";
    }
    */
    
    
    
    // ex4 //////////////////////////////////    
    /*
    imprime("ola");
    imprime("a idade e': ", 23);
    imprime(100,"euros");
    */
    
    
    
    
    // ex5 //////////////////////////////////
    /*
    cout<<"\n"<<soma()<<soma(1);
    cout<<soma(1,2)<<soma(1,2,3);
    */
    
    
    
    
   // ex6 //////////////////////////////////
   /*
   int a=5, b=10;
   troca(&a,&b);
   cout<<"\na = "<<a<<"\nb = "<<b<<endl;
   //aparece a=10 e b=5 
    */
    
    
    
    // ex7 //////////////////////////////////
    /*
    string nome, parte;
    
    cout<<"Nome: ";
    getline(cin,nome);
    
    istringstream istream(nome);  
    //nome é agora um objeto da classe istringstream. 
    // o operador >>  é um operador de extração que vai ler até encontrar um espaço em branco
    
    while(istream>>parte){
        cout<<parte<<endl;
        if(parte=="Silva"){
            cout<<"Reconheco esse individuo! \n";
        }
    
    }
     * */
   
    

    // ex8 //////////////////////////////////
    /*
    string palavra;
    cout << "Escreva \"fim\" para sair\n";
    while (true) {
        cout << "\nEscreva uma palavra: ";
        cin >> palavra;
        if (palavra == "fim")
            break;
        string inv = inverte(palavra);
        cout << "\nPalavra: " << palavra << endl;
        cout << "Palavra invertida: " << inv << endl;


        if (palavra == inv)
            cout << "\t e' palindromo!\n";
    }
    */    
    


    return 0;
}

