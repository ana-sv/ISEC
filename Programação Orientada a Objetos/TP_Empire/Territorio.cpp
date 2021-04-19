// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Territorio.h"


Territorio::Territorio() {
    pontosVitoria = 0;
    // cout << "---------->Territorio Construido! " << endl; 
}

Territorio::Territorio(const Territorio& orig) {
    //*this = orig;
    //  cout << "---------->Territorio Construido por Copia! " << endl; 
}

Territorio::~Territorio() {
    //  cout << "---------->Territorio Destruido! " << endl; 

}

string Territorio::makeDesignation( string type, int n){

    ostringstream oss;
    oss.str("");
    oss << type;
    
    if (n == 0) {
        return oss.str();
        
    } else {
        oss << n;
        return oss.str();
    }
}


 string Territorio::show() const{
      ostringstream os;
      os.str(""); 
      
      os << "___________ T e r r i t o r i o : " << designacao << endl;
      os << "Resistencia: " << resistencia << endl;
      os << "Qt Produtos: " << qtProdutosCria << endl;
      os << "Qt Ouro: " << qtOuroCria << endl;
      os << "Estado: ";
      if (conquistado==true)
          os << "conquistado" << endl;
      else
          os << "livre" << endl;
      
      return os.str(); 
 }