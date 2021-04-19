// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "Jogo.h"
#include "Snapshot.h"

int Jogo::lastLuck=0;


Jogo::Jogo() {
    fase=0; 
  //  cout << "---------->Jogo Construido" << endl;
}


Jogo::Jogo(const Jogo& orig) {

    imp = orig.imp->clone();
    m = orig.m->clone();
    fase = orig.fase;
    lastLuck = orig.lastLuck;

    for (int it = 0; it != orig.vsnap.size(); it++) {
        vsnap[it]= orig.vsnap[it];
    }

  //  cout << "---------->Jogo Construido por cópia" << endl;  
}


Jogo::~Jogo() {
    
    delete imp;
    delete m; 
    
    auto it =  vsnap.begin();

    while (it < vsnap.end() ) {
        delete *it;
        it++;

    } 
    


    cout << "---------->Jogo Destruido" << endl;

}


string Jogo::askCommand() {
    string comando;
    cout << endl;
    cout << "-> Comando: ";
    getline(cin, comando);
   // cout << " -> O comando inserido : " << comando << endl;
    return comando;
}


void Jogo::exitGame(){
    cout << endl;
    
       imp->~Imperio();
        m->~Mundo();
        lastLuck = 0;
        fase = 0;
        auto it = vsnap.begin();
        while (it < vsnap.end()) {
            delete *it;
            it++;
        }

      cout << " \t\t\t\t Saindo do jogo";

     for( int n=0; n<=10; n++)
      cout << "\t\t\t\t\t\t ."<< endl;


    exit(0);
}


string Jogo::startMenu() {
   ostringstream os;
    os.str("");

    os << "_____________________________________________________________________" << endl;
    os << "_________ E m p i r e _______________________________________________" << endl; 
    os << "_____________________________________________________________________" << endl;
    os << "_____________________________________Ajuda Comandos : help___________" << endl;
    os << "_____________________________________________________________________" << endl;

    return os.str();
}





void Jogo::startGame() {

    cout << startMenu();
    cout << endl;
    faseZero();

}



int Jogo::goodLuck(){

    // numero à sorte de 1 a 6;  
    int n =  rand()%6 + 1;
    
    setLastLuck(n); 
   
    return n;
}




bool Jogo::commands(string c) {

    string word, wordd, w;
    int n;
    
    istringstream sst(c);
    sst >> word;

    if (word == "help") {
       cout << commandHelp();
        
    } else if (word == "lista") {
        sst >> wordd;
        
        if( wordd == "" )
        cout << commandLista();
        else
         cout << commandLista(wordd);
        
    } else if (word == "sair" || word == "x") {
        exitGame();
        
    } else if (word == "grava") {   // qq fase
        sst >> wordd;
        commandGrava(wordd);

    } else if (word == "ativa") {   // qq fase
        sst >> wordd;
        commandAtiva(wordd);

    } else if (word == "apaga") {   // qq fase
       sst >> wordd;
        commandApaga(wordd);

    } else if (word == "toma") {    // debug
        sst >> wordd >> w;
        commandToma(wordd, w);

    } else if (word == "modifica") {    // debug
         sst >> wordd >> n;
         commandModifica(wordd,n);

    } else if ( word == "fevento") {    // debug
         sst >> wordd;
        commandFEvento(wordd);
    }else if( word == "turno"){ // debug 
        sst >> n;
        m->setTurno(n);
        
    } else
        return false; 

    return true;

}

string Jogo::commandHelp(){
    ostringstream os;
    os.str("");
    
    os << endl;
    os << "_________ C o m a n d o s :" << endl << endl;
   
    os << "\t[ Informacoes ]  lista | lista <territorio> | lista mundo | lista imperio | lista tecnologia " << endl;
    os << "\t[ Acoes ] avanca | sair | grava | ativa | apaga " << endl << endl;
    os << "\t[ Fase 0 - Add Territorios ] carrega <nomeFicheiro> | cria <territorio> <numero> "<< endl;        
    os << "\t[ Fase 1 - Conquista ] conquista <territorio>  | passa " << endl;
    os << "\t[ Fase 2 -  Recolha  ] maisouro | maisprod" << endl;
    os << "\t[ Fase 3 -  Compra   ] maismilitar | adquire <tipo de tecnologia> " << endl;
    os << "\t[ Fase 4 -  Eventos  ] " << endl << endl;
    os << "\t[ Debug ] toma <terr/tec> <nome> | modifica <ouro/prod> <n> | fevento <nomeEvento | turno <n> " << endl << endl;
    
    return os.str();
    
}


string Jogo::commandLista() {
    ostringstream os;
    os.str("");
    os << "______________________________________  E s t a d o  d o  J o g o : " << endl;

    os << "Ultima Sorte: " << getLastLuck() <<  endl;
    
    if ( m->getEvent() == NULL )
        os << "Proximo evento :" << m->getEvent()->getDesignacao() << endl;
    
    os << m->show();
    os << imp->show(m) << endl;

    return os.str();

}

string Jogo::commandLista(string t){

    if (t == "imperio")
        return imp->show(m);

    else if (t == "mundo")
        return m->show();

    else if (t == "tecnologia")
        return imp->showTech();

    else if (t == "eventos")
        return m->showEvents();

    else if (m->getTerritorio(t) != NULL)
        return m->getTerritorio(t)->show();

    else
        return "[ ! ] Comando Invalido! ";

}


void Jogo::faseZero() {
    cout << endl;
    cout << "___________________________________________________________________" << endl;
    cout << "__ F a s e  Z e r o :  C o n f i g u r a c a o   d o   M u n d o __" << endl;
    cout << "___________________________________________________________________" << endl << endl;
    fase = 0;

    //cria o mundo
    m = new Mundo();

    //cria imperio
    string s;
    imp = new Imperio();

    //add território inicial ao mundo
    m->addTerritorio("inicial",1);
    
    
    //add Eventos
    m->addEvents();
    m->chooseEvent();

    bool verify=false;
    string cmd, word;
    int n;

    while (!verify) {

        n = 0;

        cmd = askCommand();
        istringstream sst(cmd);
        sst >> word;

        if (word == "carrega") {
            sst >> word;
            loadTerritorios(word);

        } else if (word == "cria") {
            sst >> word >> n;
            m->addTerritorio(word, n);

        } else if (commands(cmd) == true) {
            //

        } else if (cmd == "avanca" || cmd == "go") {
            verify = true;
        } else {
            cout << endl << "[ ! ] Comando Invalido!" << endl;

        }

    }
    faseUm();


}



bool Jogo::loadTerritorios(string nomeFich){
    // recolhe territorios do ficheiro;
    ifstream f(nomeFich);
    string line; 
    
    // abrir 
    if(!f.is_open()){
        cout << "[ERRO]Abertura do ficheiro" << endl;
        return false;
    }
    
    // ler 
    while(!f.eof()){
        getline(f,line);
        
        if (line == ""){
            cout << "[ERRO] Carregamento de linha" << endl;
            return false;
        }
        
    string word, wordd;
    int n;

    istringstream sst(line);
    sst >> word >> n;
    m->addTerritorio(word,n); 
    
    }
    
    // fechar 
    f.close();
    
    cout << "[ ! ] Ficheiro carregado com sucesso." << endl;
    return true;
    

}



void Jogo::faseUm(){
    
    fase=1; 
    cout << endl;
    cout << "____________________________________________________________" << endl;
    cout << "___ F a s e  U m : C o n q u i s t a r ___ T u r n o : " << m->getTurno() << " ___" << endl;
    cout << "____________________________________________________________" << endl << endl;
    
    bool verify=false;
    string cmd, word;

    while (!verify) {

        cmd = askCommand();
        istringstream sst(cmd);
        sst >> word;

        if (word == "passa") {
            cout << "[ * ] Jogador Passou! " << endl;
             faseDois();

        } else if (word == "conquista") {
            sst >> word;
            commandConquista(word);

        } else if (commands(cmd) == true) {
            //

        } else if (cmd == "avanca" || cmd == "go") {
            verify = true;
        } else {
            cout << endl << "[ ! ] Comando Invalido!" << endl;

        }

    }
    
    faseDois();
}


bool Jogo::commandConquista(string c) {

    if (m->getTerritorio(c) == NULL) {
        cout << "[ ! ] Territorio Invalido." << endl;
        return false;
    }

    if (imp->getFmilitar() == 0) {
        cout << "[ ! ] Imperio sem forca militar." << endl;
        return false;
    }

    imp->war(m->getTerritorio(c), m, goodLuck());
    return true;

}



void Jogo::faseDois() {
    fase = 2;
    cout << endl;
    cout << "___________________________________________________________" << endl;
    cout << "__ F a s e  D o i s : R e c o l h e r ___ T u r n o : " << m->getTurno() << " ___" << endl;
    cout << "___________________________________________________________" << endl << endl;

    bool verify=false, verifyBolsa=false;
    string cmd, word;

    // recolha
    imp->collect(m);
    

    if (imp->getTecnologia("bolsa") != NULL) {
        cout << endl;
        cout << "[ * ] Deseja aceder a Bolsa de valores?" << endl;
        cout << "[ cmd ] maisouro / maisprod / avanca / help " << endl << endl;
    } else {
        cout << endl;
        cout << "[ * ] Mais nada a fazer aqui ! " << endl;
        cout << "[ tip ] Adquira a Tecnologia Bolsa de Valores futuramente! " << endl << endl;
        verify = true;
    }
    

    while (!verify) {

        cmd = askCommand();
        istringstream sst(cmd);
        sst >> word;


        if (word == "maisouro" || word == "maisprod" && verifyBolsa == false) {
  
            if (imp->findBolsaValores()->techBolsaValores(imp,word) == true)               
                verifyBolsa = true;

        } else if (commands(cmd) == true) {
            //

        } else if (cmd == "avanca" || cmd == "go") {
            verify = true;
        } else {
            cout << endl << "[ ! ] Comando Invalido!" << endl;

        }

    }

    faseTres();

}

void Jogo::faseTres() {

    fase = 3;
    cout << endl;
    cout << "_________________________________________________________" << endl;
    cout << "__ F a s e  T r e s : C o m p r a r  __ T u r n o : " << m->getTurno() << " ___" << endl;
    cout << "_________________________________________________________" << endl << endl;
    cout << "[ cmd ] Comprar forca militar ? maismilitar  " << endl;
    cout << "[ cmd ] Comprar Tecnologias ? adquire <misseis> <drones> <defesa> <bolsa> <banco>  " << endl << endl;

    bool verify = false;
    string cmd, word;

     
    while (!verify) {
       
         
        cmd = askCommand();
        istringstream sst(cmd);
        sst >> word;

        if (word == "maismilitar") {
            imp->shopMilitar();
            verify = true;

        } else if (word == "adquire") {
            sst >> word;
            imp->shopTech(word,imp);
            verify = true;            

        } else if (commands(cmd) == true) {
            //

        } else if (cmd == "avanca" || cmd == "go") {
            verify = true;

        } else {
            cout << endl << "[ ! ] Comando Invalido!" << endl;

        }

    }

    faseQuatro();

}


void Jogo::faseQuatro() {

    fase = 4;
    cout << endl;
    cout << "_____________________________________________________________" << endl;
    cout << "__ F a s e  Q u a t r o : E v e n t o s  __ T u r n o : " << m->getTurno()  << " ___" << endl;
    cout << "_____________________________________________________________" << endl;


    m->getEvent()->eventAction(imp,m);    

    m->updateMundo();

    if ( loser() == true || m->getTurno() == 13 ) 
        faseCinco();    
    
    bool verify = false;
    string cmd;
    while (!verify) {
     
        cmd = askCommand();

        if (commands(cmd) == true) {

        } else if (cmd == "avanca" || cmd == "go") {
            verify = true;

        } else {
            cout << endl << "[ ! ] Comando Invalido!" << endl;

        }

    }
    
    faseUm();
    

}







void Jogo::faseCinco() {
    
    fase = 5;
    
    updatePontuacao(imp,m);
    cout << printFinish();

 

    bool verify = false;
    string cmd, word;


    while (!verify) {

        cmd = askCommand();

        if (commands(cmd) == true) {
            //
        } else if (cmd == "go" || cmd == "avanca") {
            exitGame();           
   
        } else {
            cout << endl << "[ ! ] Comando Invalido!" << endl;

        }
    }



}



bool Jogo::loser(){

    
    // Perde...
    
    // se o unico territorio conquistado é o o inicial , e o perde depois de um evento invasao! 
    if (m->getTerritorio("inicial") != NULL && m->getVector().size() == 1  && m->getEvent()->getDesignacao() == "invasao" ) {
        cout << printLoser();
        cout << "[ ! ] Perdeu o jogo por Invasao!";
       return true;
       
       // se ficar sem nada 
    }else if ( imp->getCofre() == 0 && imp->getArmazem() == 0 && imp->getFmilitar() == 0 && imp->getPontuacao()<3 ){
       cout << printLoser();
       cout << "[ ! ] Perdeu o jogo porque gastou demasiado!";
       return true;
    
    }
    
     return false;




}

void Jogo::updatePontuacao(Imperio * imp, Mundo * m){
    
    int total=0, bonusCientifico=1, imperadorSupremo=3;
    
    total = imp->getVector().size() + 1;
    
    if( total >= 5 )
        total += bonusCientifico;
    
    
    if( m->getVector().size() == imp->checkConquered(m) )
        total += imperadorSupremo;
        
    imp->setPontuacao(total);

}


string Jogo::printFinish(){
    ostringstream os;
    os.str("");
    
    os << endl;
    os << "_____________________________________________________________________" << endl;
    os << "_________ E m p i r e ______ J o g o   T e r m i n a d o ! __________" << endl;
    os << "_____________________________________________________________________" << endl;
    os << "______P o n t u a c a o : " << imp->getPontuacao() << " __________________________________________" << endl;
    os << "_____________________________________________________________________" << endl << endl;
    
    return os.str();

}



string Jogo::printLoser(){
    ostringstream os;
    os.str("");

    os << endl;
    os << "_____________________________________________________________________" << endl;
    os << "____________________ P e r d e u   o   J o g o ! ____________________" << endl;
    os << "_____________________________________________________________________" << endl;
    os << "_____________________________________________________________________" << endl << endl;

    return os.str();

}





void Jogo::commandGrava(string s) {

    vsnap.push_back(new Snapshot(s));
    //cout << vsnap.back()->ident;
    vsnap.back()->m = *m;
    vsnap.back()->imp = *imp;
    vsnap.back()->lastLuck = lastLuck;
    

    if (vsnap.data() != nullptr)
        cout << endl << "[ ! ]Podera reativar o jogo mais tarde pelo identificador " << s << endl;
    else
        cout << endl<< "[ ! ] Erro ao gravar snapshot! " << endl;

}





void Jogo::commandAtiva(string s){

    int it;
  
    if ( vsnap.size()== 0  ){
        cout << "[ ! ] Vector de snapshots vazio!  ";
        return;
    }
        
    for (it = 0; it != sizeof (vsnap); it++) {

        if (vsnap[it]->ident == s) {
            *m = vsnap[it]->m;
            *imp = vsnap[it]->imp;
            cout << "[ * ] Snapshot Ativado!  ";
            return;

        }
    }
    cout << "[ ! ] Snapshot nao encontrado!  ";

}


void Jogo::commandApaga(string s){

    int it;
    
        if ( vsnap.size()== 0  ){
        cout << "[ ! ] Vector de snapshots vazio!  ";
        return;
    }
    
    
    for (it = 0; it != sizeof (vsnap); it++) {

        if (vsnap[it]->ident == s) {
            
            vsnap.erase( vsnap.begin()+it-1);
 
            cout << "[ * ] Snapshot Apagado!  ";
            return;

        }
       
    }
    
    cout << "[ ! ] Snapshot nao encontrado!  ";
    
    
}




void Jogo::commandToma( string type, string word){

    if( type == "terr" ){
        if ( m->getTerritorio(word) != nullptr )
            m->getTerritorio(word)->setEstado(true);
        else 
            cout << "[ ! ] Territorio invalido! " << endl;

    }else if ( type == "tec" ){
        imp->addTech(word,imp);
    
    }else{
        cout << "[ ! ] Comando Debug Invalido!" << endl; 
    
    }

}

void Jogo::commandModifica(string type, int n) {
    
    if (!n) {
        n = 0;
    }

    if (type == "ouro") {
        imp->setCofre(n);
    } else if (type == "prod") {
        imp->setArmazem(n);
    } else {
        cout << "[ ! ] Comando Debug Invalido!";
    }



}


void Jogo::commandFEvento( string type ){
    
    if ( m->findEvent(type) !=  nullptr )
        m->setEvent(  m->findEvent(type)) ;
    else 
        cout << "[ ! ] Comando Debug Invalido!";

}