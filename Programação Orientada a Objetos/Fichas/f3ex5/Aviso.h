// Ana Videira | 2015012218 | 2020/2021

#ifndef AVISO_H
#define AVISO_H

#include "Prego.h"

class Aviso{

    string texto;
    Prego &prego;

public:

    Aviso(string s, Prego &p) : prego(p) {
        texto = s;
        cout << "--> Aviso Construido!" << endl;
    };

    ~Aviso() {
        cout << "--> Aviso destruido!" << endl;
    };

    void getInfo(ostringstream &os) const {
        string s;
        os.str("");
        os << "\nAviso: " << texto << " - Prego:" << prego.getXY(s) << endl << endl;
    }

};



#endif /* AVISO_H */

