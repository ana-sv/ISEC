// Ana Videira | 2015012218 | 2020/2021

#include "TV.h"

using namespace std;


int main(int argc, char** argv) {
    
    TV a({"RTP1", "RTP2", "SIC", "TVI"});
    
    int escolha=0, canal;
    ostringstream s;
    
    while(escolha!=7)
    {
        cout << "\nMenu:\n";
        cout << "1 - Ligar TV\n";
        cout << "2 - Desligar TV\n";
        cout << "3 - Aumentar volume\n";
        cout << "4 - Diminuir volume\n";
        cout << "5 - Mudar Canal\n";
        cout << "6 - Estado\n";
        cout << "7 - Sair\n\n";
        cout << "Resposta: ";
        cin >> escolha;
        
        if(escolha==1) // ligar
        {
            a.ligar();
        }
        else if(escolha==2) // desligar
        {
            a.desligar();
        }
        else if(escolha==3) // aumentar volume
        {
            a.aumentarVolume();
        }
        else if(escolha==4) // diminuir volume
        {
            a.diminuirVolume();
        }
        else if(escolha==5) // mudar de canal
        {
            cout<< "Canal: ";
            cin >> canal;
            a.mudarCanal(canal);
        }
        else if(escolha==6) // estado
        {
            a.gerarStream(s);
            cout << s.str();
        }
        else if(escolha==7)
        {
            return 0;
        }
        else
        {
            cout<<"Insira uma opcao va'lida!";        
        }
    }

    return 0;
}

