// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#ifndef IMOVEL_H
#define IMOVEL_H


#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;




class Imovel {
   
public:
    
    //Imovel(float a):area(a), codigo(++conta){ cout << "Imovel Construido!" << endl;} ;
    
    Imovel(float a): area(a){
        conta++;
        numCodigo = conta;
        cout << "Imovel Construido!" << endl;
    };
    
    virtual ~Imovel(){ cout << "Imovel Destruido!" << endl; };
  
   float obtemArea() const { return area; };
   int getNumCodigo() const { return numCodigo; };
   
    virtual float obtemPreco() const = 0;       // só promessa, funcoes na classes filhas
                                                  // ou   virtual int obtemPreco() const { return 0; }
    virtual string obtemCodigo() const = 0 ;
    virtual string obtemDescricao() const = 0;
 
    
protected:
    static int conta; 
    int numCodigo;
    float preco;
    float area;
    
}; 


int Imovel::conta=0;


// operador para que
// cout << l1;      funcione em vez de  cout  << l1.obtemDescricao

  ostream & operator <<( ostream & saida, const Imovel & x){
        saida <<  x.obtemDescricao(); 
        return saida;    
    };
    
    
    
    
#endif /* IMOVEL_H */

