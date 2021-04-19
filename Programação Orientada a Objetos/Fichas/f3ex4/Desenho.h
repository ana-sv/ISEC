// Ana Videira | 2015012218 | 2020/2021


#ifndef DESENHO_H
#define DESENHO_H

#include "Rectangulo.h"
#include <vector>
#include <string>
#include <sstream>

class Desenho {
    string nome;
    vector <Rectangulo> v; 
    
public:
    Desenho(const string &s);
    ~Desenho();
    
    void infoDesenho( ostringstream &os ) const;
    
    bool addRectangulo( const Rectangulo &r);
      
    int somaArea()const;
    void cleanRectangulo( int areaLimite );  
    
    void getRectangulo( vector<Rectangulo> &c) const;
    
    

};

#endif /* DESENHO_H */

