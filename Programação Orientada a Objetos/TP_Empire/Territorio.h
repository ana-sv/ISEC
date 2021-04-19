// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#ifndef TERRITORIO_H
#define TERRITORIO_H


#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <ctime>


using namespace std;


class Territorio {
    
public:
    
    Territorio();
    Territorio(const Territorio& orig);
    virtual ~Territorio();

    void setDesignacao(string s) { designacao = s; };
    void setResistencia(int n){ resistencia = n; };
    void setQtProdutos(int n){ qtProdutosCria = n; };
    void setQtOuro(int n){ qtOuroCria = n; };
    void setEstado(bool est){ conquistado = est; };
       
    string getDesignacao() const { return designacao;};
    int getResistencia() const { return resistencia; };
    int getQtProdutos() const { return qtProdutosCria; };
    int getQtOuro() const { return qtOuroCria; };
    bool getEstado() const { return conquistado; }; 
    int getVictoryPoints() { return pontosVitoria; };
 
    string makeDesignation(string type, int n);
    
   string show() const;
   
  virtual void update(int turno){}; // só promessa
  virtual Territorio *clone(){ return new Territorio(*this); };
    
    
protected: 
    string designacao;
    int resistencia;
    int qtProdutosCria;
    int qtOuroCria;
    int pontosVitoria;
    bool conquistado; 
};

#endif /* TERRITORIO_H */

