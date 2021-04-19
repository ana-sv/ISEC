// Ana Videira | 2015012218 | 2020/2021

#ifndef PREGO_H
#define PREGO_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Prego {
    int x, y;

public:

    Prego(int a, int b) : x(a), y(b) {
        cout << "Prego Construido" << endl;
    }

    ~Prego() {
        cout << "Prego Destruido!" << endl;
    }

    string & getXY(string &s) const {
        ostringstream os;
        os << "(" << x << "," << y << ")";
        s = os.str();
        return s;
    }

    void mudaDeSitio(int a, int b) { x = a; x = b; };

};



#endif /* PREGO_H */

