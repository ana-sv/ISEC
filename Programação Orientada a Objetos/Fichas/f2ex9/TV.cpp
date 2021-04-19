// Ana Videira | 2015012218 | 2020/2021

#include "TV.h"


TV::TV(initializer_list <string> s){
    on = false;         // inicializa com a tv desligada 
    int volume=0;
    int atual=0;
    
    for( auto x=s.begin(); x<s.end(); x++){
        canais.push_back(*x);
    }    
    cout<<atual;
}

void TV::ligar() {
    if (on == true)
        cout << "Ja' esta' ligada\n";
    else {
        on = true;
        cout << "Televisao ligada\n";
    }
}

void TV::desligar() {
    if (on == false)
        cout << "Ja' esta' desligada\n";
    else {
        on = false;
        cout << "Televisao desligada\n";
    }
}

void TV::aumentarVolume() {
    if ((volume >= 0 || volume < 10) && on == true) {
        volume++;
        cout << "Volume aumentado!\n";
    }
    else
        cout << "Erro!\n";

}

void TV::diminuirVolume() {
    if ((volume > 0 || volume <= 10) && on == true) {
        volume--;
        cout << "Volume diminuido!\n";
    } else
        cout << "Erro!\n";

}

void TV::mudarCanal(int n ){
    if(n>0 && on==true){
        atual=n;
        cout <<"Canal Mudado!\n";
    }
    else
        cout<<"Canal inválido!\n";
}


void TV::gerarStream(ostringstream &s)const{
    
    if(on==true){

        s<<"Estado: Ligado" << endl;
        s<<"Canal Atual: "<< atual << endl;
        s<<"Volume: " << volume  << endl;
    }
    else
        s<<"Estado: Desligado\n";
    
  
}