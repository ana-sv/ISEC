// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218


#include "Invasao.h"

Invasao::Invasao() {
    designacao = "Invasao";
    ident = "invasao";
    descricao = "Um dos territorios conquistados e invadido.";
}

Invasao::Invasao(const Invasao& orig) {
}

Invasao::~Invasao() {
}

bool Invasao::eventAction(Imperio * imp, Mundo * m) {
    
cout << endl << "Evento "<< designacao << " ativo ! " << endl;

    int luck =  rand()%6 + 1;
    int it, resistencia=0;
    int n = m->getVector().size();
    
    
    for ( it = n;
            it != 0 ||  m->getVector()[it]->getEstado() == false;
                 it--);      
        
            
    if (m->getAno() == 1)
        forcaInvasao = 2;
    else
        forcaInvasao = 3;
    
    
    if( imp->getTecnologia("defesa") != NULL ) 
        resistencia = m->getVector()[it]->getResistencia()+1;
    else 
        resistencia= m->getVector()[it]->getResistencia();
    
    
    if ( forcaInvasao + luck < resistencia ){
        cout << "[ * ] Invasao falhou! " << endl;
        return false ;   
        
    }else{ 
        m->getVector()[it]->setEstado(false);
        cout << "[ * ] Invasao Conseguida! ";
        cout << " Imperio perdeu o territorio " << m->getVector()[it]->getDesignacao() << " !" << endl;
        return true ;     
    

    }
    
    

}

