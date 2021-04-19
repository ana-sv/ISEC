// Ana Videira | 2015012218 | 2020/2021

// Exemplo de Agregação 
// Quando o aviso é destruido , nada acontece ao prego
// Existe uma relação de agregação entre as duas classes 

#include "Aviso.h"

int main(int argc, char** argv) {

   ostringstream os;
    
    Prego pa(1,2);
    Aviso a("sou o aviso a ", pa);
    a.getInfo(os);
    cout << os.str();
    
    Prego pb(3,4);
    Aviso b("sou o aviso b",pb);
    b.getInfo(os);
    cout << os.str();
    
    pb.mudaDeSitio(8,9);
    b.getInfo(os);
    cout << os.str();
    
    
    return 0;
}

