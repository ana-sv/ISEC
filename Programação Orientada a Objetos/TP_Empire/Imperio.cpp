// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Imperio.h"

Imperio::Imperio() {
    
    armazem=0;
    pontuacao=0;
    armazem=0;
    maxArmazem=3;
    cofre=0;
    maxCofre=3;  
    fMilitar=3; /// ? 
    maxFmilitar=3;
   
   // cout << "---------->Imperio Construido!" << endl;
}

Imperio::Imperio(const Imperio& orig){
    
    pontuacao = orig.pontuacao;
    armazem = orig.armazem;
    maxArmazem = orig.maxArmazem;
    cofre = orig.cofre;
    maxCofre = orig.maxCofre;
    fMilitar = orig.fMilitar;
    maxFmilitar = orig.fMilitar;
    
    for (int it = 0; it != orig.vtec.size(); it++) {
       vtec.push_back( orig.vtec[it]->clone() );
   }
   
  //  cout << "---------->Imperio Construido por Copia!" << endl;
    
}


Imperio::~Imperio() {
    auto it = vtec.begin();
    
    while(it < vtec.end()){
        delete *it;
        it++;
    }
    //cout << "---------->Imperio Destruido!" << endl;
}


bool Imperio::addArmazem(int n) {

    if (getArmazem() + n <= getMaxArmazem()) {
        setArmazem(getArmazem() + n);
        cout << "[ * ] Adicionados produtos ao Armazem!" << endl;
        return true;
    } else {
        cout << "[ ! ] Demasiados produtos no Armazem! Desperdicio! " << endl;
        return false;
    }

}


bool Imperio::addCofre(int n) {

    if (getCofre() + n <= getMaxCofre() ) {
        setCofre(getCofre() + n);
        cout << "[ * ] Adicionado ouro ao Cofre!" << endl;
        return true;
    } else {
        cout << "[ ! ] Demasiado ouro no Cofre! Desperdicio! " << endl;
        return false;
    }

}


void Imperio::decreaseFmilitar(){
    
    if (fMilitar > 0)
        fMilitar--;
    
    if(fMilitar == 0 )
        cout << "[ ! ] Imperio ficou sem forca militar. " << endl;
}


void Imperio::increaseFmilitar(){
    
    if (fMilitar <  maxFmilitar )
        fMilitar++;
    
    if(fMilitar == maxFmilitar  )
        cout << "[ ! ] Imperio com nivel maximo de forca militar. " << endl;
}


bool Imperio::payOuro( int custo ){
    
    if( cofre == 0 ){
        cout << "[ ! ] Imperio tem o cofre vazio!" << endl;
        return false;       
    }
    
    else if( cofre - custo >= 0){
        cofre -= custo;
        cout << "[ * ] Pagamento com ouro efetuado com sucesso! " << endl;
        
        if( cofre == 0 )
            cout << "[ ! ] Cofre agora vazio! " << endl;
        
        return true;
    }

}


bool Imperio::payProd( int custo ){
    
    if( armazem == 0 ){
        cout << "[ ! ] Imperio tem o armazem vazio!" << endl;
        return false;       
    }
    
    else if( armazem - custo >= 0){
        armazem -= custo;
        cout << "[ * ] Pagamento com produtos efetuado com sucesso! " << endl;
        
        if( armazem == 0 )
            cout << "[ ! ] Armazem agora vazio! " << endl;
        
        return true;
    }

}


string Imperio::show( Mundo * m) const {
    ostringstream os;
    os.str("");

    os << "_________________________________ I m p e r i o [ano " << m->getAno();
    os << "] [ turno " << m->turno << " ]" << endl;
    
    os << "Pontuacao: " << pontuacao << endl;
    os << "Armazem de Produtos: " << armazem << " (Max: " << maxArmazem << ") " << endl;
    os << "Cofre de Ouro: " << cofre << " (Max:" << maxCofre << ") " << endl;
    os << "Forca Militar: " << fMilitar << endl;

    os << "Territorios Conquistados: " << endl;
    for (int it = 0; it != m->vt.size(); it++) {
        if (m->vt[it]->getEstado() == true)
            os << "--->" << m->vt[it]->getDesignacao() << endl;
    }

    os << "Tecnologias: " << endl;
    for (int it = 0; it != vtec.size(); it++)
        os << vtec[it]->getDesignacao() << endl;


    return os.str();
}


void Imperio::war(Territorio * t, Mundo * m, int luck) {
    //cout << "SORTE: " << luck << "FMILITAR: " << Fmilitar<< endl;

    //check se é ilha 
    if (dynamic_cast<Ilha*> (t) != nullptr) {

        if (checkConquered(m) < 5 || getTecnologia("misseis") != NULL ) {
            cout << "[ ! ] Sem condicoes para conquistar ilha " << endl;
            decreaseFmilitar();
            return;
        }
    } else if( t->getEstado() == true ){
        cout << "[ ! ] Territorio ja' conquistado! " << endl;
        return;
    }
    

    if (luck + fMilitar >= t->getResistencia()) {
        t->setEstado(true);
        pontuacao += t->getVictoryPoints();
        cout << "[ * ] " << t->getDesignacao() << " conquistado!" << endl;

    } else {
        cout << "[ * ] Perdeu a batalha!" << endl;
        decreaseFmilitar();

    }
}


int Imperio::checkConquered(Mundo * m) {

    int conq = 0;
   
    for (int it = 0; it != m->vt.size() ; it++) {
        
        if (m->vt[it]->getEstado() == true )
            conq++;
    }
    
    return conq;
}


void Imperio::collect(Mundo * m) {
    
    int ouro = 0, produtos = 0;

    for (int it = 0; it != m->vt.size(); it++) {

        if (m->vt[it]->getEstado() == true) {

            if (cofre < maxCofre) {
                cofre += m->vt[it]->getQtOuro();
                ouro += m->vt[it]->getQtOuro();
            }
            if (armazem < maxArmazem) {
                armazem += m->vt[it]->getQtProdutos();
                produtos += m->vt[it]->getQtProdutos();
            }

        }
    }

    cout << "[ * ] Total de Ouro Recolhido: " << ouro << endl;
    cout << "[ * ] Total de Produtos Recolhido: " << produtos << endl;


}



Tecnologia* Imperio::getTecnologia(string ident) {

    for (int it = 0; it != vtec.size(); it++) {

        if (vtec[it]->getIdent() == ident)
            return vtec[it];

    }

    return NULL;
}


BolsaValores * Imperio::findBolsaValores(){
    
    for (int it = 0; it != vtec.size(); it++) {

        if (vtec[it]->getIdent() == "bolsa")
            return dynamic_cast < BolsaValores * >( vtec[it] ) ;

    }

    return NULL;


}


void Imperio::shopMilitar() {

    if (payOuro(1) == true && payProd(1) == true) {

        if (fMilitar < maxFmilitar) {
            fMilitar++;
            cout << "[ * ] Forca Militar incrementada com sucesso!" << endl;
        } else if (fMilitar == maxFmilitar)
            cout << "[ ! ] Forca Militar no nivel Maximo!" << endl;
    }
    
}

bool Imperio::addTech(string t, Imperio * i) {

    if (t == "bolsa") {
        vtec.push_back(new BolsaValores());

    } else if (t == "misseis") {
        vtec.push_back(new MisseisTeleguiados());

    } else if (t == "defesas") {
        vtec.push_back(new DefesasTerritoriais());

    } else if (t == "drones") {
        vtec.push_back(new DronesMilitares(i));

    } else if (t == "banco") {
        vtec.push_back(new BancoCentral(i));

    } else {
        cout << "Insira uma Tecnologia valida!" << endl;
        return false;

    }
    return true;

}



void Imperio::shopTech(string t, Imperio * i) {

    if (addTech(t, i) == true) {

        if (payOuro(vtec.back()->getCusto()) == false) {
            cout << "[ ! ] Nao tem ouro para adquirir a Tecnologia " << vtec.back()->getDesignacao() << endl;
            vtec.pop_back();
            return;
        }

    }

    cout << "[ * ] Adquiriu a Tecnologia " << vtec.back()->getDesignacao() << endl;



}


string Imperio::showTech() const {
    ostringstream os;
    os.str("");

    for (int it = 0; it != vtec.size(); it++)
         os << vtec[it]->show() << endl;
                 
    if (vtec.size() == 0)
        os << "[ ! ] Vector de tecnologias vazio!" << endl;
    
    return os.str();
    
}



