// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

//Exame 1920 - Época Normal - Exercicio 7


#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

class Funcionario {
    
public:
    Funcionario(const string &n) : nome(n) {};
    virtual string getNome()const { return nome; };
    virtual string cumprimentar()const = 0;

protected:
    string nome;
};


class Doutor : public Funcionario{

public:

    Doutor(const string &no) : Funcionario(no) { };

    string cumprimentar() const override {
        
        ostringstream os;
        os << "Bom dia Doutor " << getNome() << endl;
        return os.str();
    }
    
};
 
class Engenheiro : public Funcionario {

public: 
    Engenheiro(const string &no) : Funcionario(no) { };

    string cumprimentar() const override {
        
        ostringstream os;
        os << "Bom dia Engenheiro " << getNome() << endl;
        return os.str();
    }
 
};

class Empresa {
    
public:

    Empresa() {
        funcionarios.push_back(new Doutor("D1"));
        funcionarios.push_back(new Doutor("D2"));
        funcionarios.push_back(new Engenheiro("E1"));
        funcionarios.push_back(new Engenheiro("E2"));
    }
    
    
  void cumprimentar()const{
      for(auto a : funcionarios)
        cout << a->cumprimentar();
  }
  
private:
    vector<Funcionario*>funcionarios;


};



int main(int argc, char** argv) {
    
    Empresa empresa;
    empresa.cumprimentar();

    return 0;
}

