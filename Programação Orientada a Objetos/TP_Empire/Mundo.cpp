// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Mundo.h"
#include "Abandonado.h"
#include "Inicial.h"


Evento * Mundo::event = nullptr;

 
Mundo::Mundo() {
  //  cout << "---------->Mundo Construido" << endl;
    turno=1;
}

Mundo::Mundo(const Mundo& orig)
{
    for (int it = 0; it < orig.vt.size(); it++) {
        cout << " aqui!" << endl;
        vt.push_back(orig.vt[it]->clone());


    }

    for (int it = 0; it < orig.ve.size(); it++) {
        cout << " ali!" << endl;
        ve.push_back(orig.ve[it]->clone());
    }

    turno = orig.turno;
    cout << " acola'!" << endl;
    event = orig.event->clone();

  //  cout << "---------->Mundo Construido por copia" << endl;

}


Mundo::~Mundo() {

    auto it = ve.begin();
    auto itt = vt.begin();

    while (it < ve.end()) {
        delete *it;
        it++;
    }

    while (itt < vt.end()) {
        delete *itt;
        itt++;

    }
    event = NULL;
    delete event;

   // cout << "---------->Mundo Destruido" << endl;
}


int Mundo::getAno() const {
    if( turno <= 6  )
        return 1;
    else 
        return 2; 
}





bool Mundo::addTerritorio(string nome, int n){

    if ( !n )
        n=1;

    for (int i = 0; i < n; i++) {

        if( nome == "inicial"){
            vt.push_back(new Inicial());        
        }
        else if (nome == "planicie") {
            vt.push_back(new Planicie());

        } else if (nome == "montanha") {
            vt.push_back(new Montanha());

        } else if (nome == "fortaleza") {
            vt.push_back(new Fortaleza());

        } else if (nome == "mina") {
            vt.push_back(new Mina());

        } else if (nome == "duna") {
            vt.push_back(new Duna());

        } else if (nome == "castelo") {
            vt.push_back(new Castelo());
            
        } else if (nome == "refugio") {
            vt.push_back(new Refugio());
            
        } else if (nome == "pescaria") {
            vt.push_back(new Pescaria());

        } else {
            cout << "[ ! ] Insira um Territorio valido!" << endl;
            return false;
            
        }
        cout << "[ * ] Territorio " << vt.back()->getDesignacao() << " criado !" << endl;
    }
    
}

string Mundo::show() const {
    ostringstream os;
    os.str("");
    os << endl;
     
    os << "___________________________________  M u n d o  [ano " <<  getAno();
    os << "] [ turno " << turno << " ]" << endl;
    
    for (int it = 0; it != vt.size(); it++) {
        
        os << vt[it]->getDesignacao(); 
        
        if (vt[it]->getEstado() == true)
            os << " - conquistado";
        else
            os << " - livre";
        os << " r" << vt[it]->getResistencia();
        os << endl;
    }

    return os.str();
}


Territorio* Mundo::getTerritorio(string d) {

    for (int it = 0; it != vt.size(); it++) {
        
        if ( vt[it]->getDesignacao() == d )
            return vt[it];
    }
    
    return NULL;
}


void Mundo::updateMundo(){
    turno++;
    
    chooseEvent();
    
    for (int it = 0; it != vt.size(); it++) {
        vt[it]->update(turno);
        // cout <<"[ ! ] "<< vt[it]->getDesignacao() << " successfully updated! " << endl;
    }
    
    
}



bool Mundo::addEvents(){

    ve.push_back( new Abandonado() );
    ve.push_back( new Invasao() );
    ve.push_back( new Alianca() );
    ve.push_back( new Evento() );
   // cout << "[ ! ]Vector de Eventos Operacional! " << endl;
    
}



string Mundo::showEvents() {
    ostringstream os;
    os.str("");

    for (int it = 0; it != ve.size(); it++)
        os << ve[it]->show();

    return os.str();

}


Evento * Mundo::findEvent(string s) {

    for (int it = 0; it != ve.size(); it++) {
        if (ve[it]->getIdent() == s)
            return ve[it];
    }
    
    return nullptr;

}



void Mundo::chooseEvent() {

    int n = rand() % ve.size(); // de 0 a size-1
    
    event = ve[n];

}