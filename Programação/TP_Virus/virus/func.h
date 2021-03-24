// Trabalho Pratico Programacao - LEI-CE
// DEIS-ISEC 2019-2020
// Ana Rita Santos Videira | 2015012218 | a21250074@isec.pt 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "structs.h"

#define FILE_LOCAIS "E3.bin"
#define FILE_PESSOAS "pessoasA.txt"


//BACKUP  - Não Funcional
//psimulacao goBack(psimulacao s, psimulacao b); 
//psimulacao loadBackup( psimulacao s, psimulacao b );


//SIMULACAO
psimulacao deletePerson(psimulacao s, char nome[MAX_NAME], int ident);
int verifyLink(psimulacao s, int id);
ppessoa findPerson(psimulacao s, char nome[MAX_NAME]);
psimulacao transferPerson(psimulacao s);
int verifyID( psimulacao s , int id);
void addInfected(psimulacao s);
int countDays(psimulacao s);
int countPersons (psimulacao s, char c);
int countAllPeople( psimulacao s);
void showStatistics(psimulacao s);
ppessoa infectPeople(ppessoa p, int n);
void immunity(ppessoa p);
void recovery( ppessoa p );
ppessoa infectionTime(ppessoa p);
int dissemination(int total);
psimulacao simulationGO(psimulacao s, psimulacao b); 
void freeList(psimulacao s);
void saveData( psimulacao s );
void simulationEXIT(psimulacao i); 



//PREPARACAO
void showInfo(psimulacao s);
psimulacao addLocal(psimulacao s, local l);
int addPessoa(psimulacao s, ppessoa p, int i);
psimulacao simulatioSettings(psimulacao s,ppessoa p, plocal l ,int *tam);
void showPessoas(ppessoa p);
ppessoa loadList( ppessoa p);  // falta validar ligacoes 
void showLocais(local *v, int *tam);
local * loadVetor(int *n);


// UTILS   
void exitProgram(ppessoa p, local *l );
int printSimulationMenu();
int printMenu();
void initRandom();
int intUniformRnd(int a, int b);
int probEvento(float prob);