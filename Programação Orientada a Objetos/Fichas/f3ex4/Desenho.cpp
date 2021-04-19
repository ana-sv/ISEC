// Ana Videira | 2015012218 | 2020/2021



#include "Desenho.h"

Desenho::Desenho(const string &s) {
    nome=s;
    cout << "Desenho Construido!" << endl;
}

Desenho::~Desenho() {
    cout << "Desenho " << nome << " Destruido!" << endl;
}

void Desenho::infoDesenho( ostringstream &os ) const {
    
    ostringstream as;
    
    os.str(""); // limpa conteudo de os
    for( int i=0; i<v.size() ; i++){
        os << "Rectangulo " << i+1 << endl;
        v[i].getInfo(as); // função da classe rectangulo
        os << as.str();
        os << endl;
    }
}


bool Desenho::addRectangulo( const Rectangulo &r){
    //adiciona retangulo se não houver 
    // sobreposição sobre outro já no desenho
    
    // falta 
    
    
    v.push_back(r);
}

int Desenho::somaArea()const{
    int total;
    
    for(int i=0; i<v.size(); i++){
        total=total+v[i].area(); 
    }
    return total; 
}

void Desenho::cleanRectangulo ( int areaLimite ){
    int e=0;
    
    for(int i=0; i<v.size() ; i++){
        
        if( v[i].area() > areaLimite ){
            v[i]=v[v.size() - 1];
            v.pop_back();
            e++;
        }
    }
    cout << "\n" << e << "rectangulos eliminados!" << endl; 
    
}

void Desenho::getRectangulo( vector<Rectangulo> &c) const{
    vector <Rectangulo>::const_iterator it; // iterador para o vector
    
    for( it=v.begin(); it<v.end(); it++){
        
        if(it->getAlt()==it->getLarg())
            c.push_back(*it);
        
    }

}