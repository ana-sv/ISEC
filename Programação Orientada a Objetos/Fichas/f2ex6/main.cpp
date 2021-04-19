// Ana Videira | 2015012218 | 2020/2021

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Auto{
    string marca;
    string modelo;
    string combustivel;
    string matricula;
    int ano;
    
public:
    Auto(){ cout << "\n---- Novo Objeto Auto ----\n "; }; //contrutor por omissao
    Auto(const string &mar, const string &mod, const string &comb, const string &mat, const int a); //contrutor
    
    //Para buscar o que está em privado
    string getMarca(){return marca;};    
    string getModelo(){return modelo;};
    string getCombustivel(){return combustivel;};
    string getMatricula(){return matricula;};
    int getAno(){return ano;};
    
    //Para alterar o que está em privado
    void setMarca(string m){ marca=m; };  // se usasse nomes iguais tinha que fazer   void setMarca(string marca){ this->marca=marca; };  
    void setModelo(string mo){ modelo=mo; };
    void setCombustivel(string m);
    void setMatricula(string m);
    void setAno(int a);
    
    
    void print() const; // Imprime info de objeto da class
    string juntaStrings() const; // junta todas as info de objeto numa só string 
};



Auto::Auto(const string &mar, const string &mod, const string &comb, const string &mat, const int a) {
    cout << "\n---- New Object by constructor 2 ----\n";
    marca = mar;
    modelo = mod;
    combustivel = comb;
    matricula = mat;
    ano = a;
}

 void Auto::setCombustivel(string m){
    if(m=="gasolina" || m=="gasoleo" || m=="gas")
        combustivel=m;
    else
        cout << "\n\t -> Combustivel invalido"; 
        combustivel="ERRO";
};

void Auto::setMatricula(string m){
    if( sizeof(m)== 8)
        matricula=m;
    else{
        cout << "\n\t -> Matricula invalida"; 
        matricula="ERRO";

    }
        
}

void Auto::setAno(int a){
    if(a>1800)
        ano = a;
    else{
        cout << "\n\t -> Ano invalido";
        ano = 000;
    }

}



void Auto::print() const   {  // se nao utilizar o const, tenho que usar as funçõe getMarca, getModelo...
    cout << "\nMarca: " << marca << endl;
    cout << "Modelo: "<< modelo << endl;
    cout << "Combustivel: " << combustivel << endl;
    cout << "Matricula: "<< matricula << endl;
    cout << "Ano: " << ano << endl;
}


string Auto::juntaStrings() const {
    ostringstream oss;
    
    oss << marca << "*" << modelo << "*" << matricula << "*" << combustivel << "*" << ano;
    
    return oss.str();
}




int main(int argc, char** argv) {


    Auto a;
    a.print();
    
    Auto b("FIAT", "PUNTO", "Gasolina","26-34-GZ", 2000);
    b.print();
    
    b.setAno(1);
    b.setCombustivel("buh");
    b.setMatricula("buh");

    b.print();

           
    return 0;
}

