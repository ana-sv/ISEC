
#include "Snapshot.h"
#include "Mundo.h"

Snapshot::Snapshot(string nome) {
     ident=nome; 
   //  cout << "Snapshot Construido!" << endl;
}

Snapshot::Snapshot(const Snapshot& orig) {
    ident = orig.ident;
    imp = orig.imp;
    m = orig.m;
    lastLuck= orig.lastLuck;
    //cout << "Snapshot Construido por copia! "<< endl;
    
}

Snapshot::~Snapshot() {
    //cout <<" Snapshot Destruido!"" << endl;
}

string Snapshot::show(){

    ostringstream os;
    os.str("");
    
    os << " Snapshot: " << ident << endl;
    os << "lastLuck: " << lastLuck;
    os << m.show();
        
    return os.str();
}