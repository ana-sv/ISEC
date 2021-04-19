// Ana Videira | 2015012218 | 2020/2021

#include "Desenho.h"

int main(int argc, char** argv) {
    
    ostringstream os;
    
    Desenho d("Novo");
    d.addRectangulo(Rectangulo(Ponto(1,1),4,2));
    
    Rectangulo r1(Ponto(4,2), 2,1);
    d.addRectangulo(r1);
    
    d.infoDesenho(os);
    cout << os.str() << endl;
    
    
    
    return 0;
}

