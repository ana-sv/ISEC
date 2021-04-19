// Ana Videira | 2015012218 | 2020/2021

#ifndef PONTO_H
#define PONTO_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;


class Ponto {

private:
    int x;
    int y;
public:

    Ponto(){ this->x = 0;this->y = 0; };   // ??
    Ponto(int x, int y) { this->x = x; this->y = y; }; //this porque as variaveis são iguais

    int getX(){ return x; };
    int getY() {return y; };
    
    int setX( int x ){ this->x=x; };
    int setY (int y ){ this->y=y; };
    
    void print() const{ cout << "\nPonto: " << x << "," << y << endl; };
    
    double distance(Ponto p){
        double aux = sqrt(pow(x - p.x,2.0) + pow(y -p.y, 2.0));
        cout << "Distance: " << aux << endl;
        return aux;
    };
    
    string & infoTxt(string &s) const{
        ostringstream os; 
        os << "( " << x <<" , " << y << " ) ";
        s = os.str();
        return s;
    }   
    
    void move(int a, int b){
        x+=a;
        y+=b;
    }

};

#endif /* PONTO_H */

