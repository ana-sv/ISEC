// Trabalho Pratico Programacao - LEI-CE
// DEIS-ISEC 2019-2020
// Ana Rita Santos Videira | 2015012218 | a21250074@isec.pt 

#include "func.h"




int main(int argc, char** argv) {

    initRandom();
    
    //cria vetor dinamico de estruturas local
    int tam = 0;
    local *locais= loadVetor(&tam);
    //showLocais(locais,&tam);
    
    //cria lista ligada de estruturas pessoas
    ppessoa pessoas = NULL;
    pessoas = loadList(pessoas);
    // showPessoas(pessoas);
    
    // lista ligada de locais(horizontal) e pessoas(vertical)
    psimulacao s = NULL;
    
    //lista para back up; 
   psimulacao b = NULL;


    // Testar retroceder iterações
    //s = simulatioSettings(s, pessoas, locais, &tam); 
    //  addInfected(s);
    //   b = loadBackup(s,b );
    // s = goBack(s,b);

    



  
    //Menu
    do {

        switch (printMenu()) {

            case 1: showLocais(locais, &tam); break;
            case 2: showPessoas(pessoas); break;
            case 3: s = simulatioSettings(s, pessoas, locais, &tam); break;
            case 4:

                if (Config == 1) {
                    do {
                        switch (printSimulationMenu()) {
                            case 1: s = simulationGO(s,b); break;
                            case 2: s = goBack(s,b); break;
                            case 3: showInfo(s); break;
                            case 4: showStatistics(s); break;
                            case 5: addInfected(s); break;
                            case 6: s = transferPerson(s); break;
                            case 7: simulationEXIT(s); return 0;
                            default: printf("--------->Insira uma opcao valida");
                        }
                    } while (1);
                }
                
                break;
                
            default: printf("--------->Insira uma opcao valida");
        }

    } while (1);
    
   
    
    
 
        exitProgram(pessoas,locais);
    
        return (EXIT_SUCCESS);
    }

