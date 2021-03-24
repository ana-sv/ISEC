// Trabalho Pratico Programacao - LEI-CE
// DEIS-ISEC 2019-2020
// Ana Rita Santos Videira | 2015012218 | a21250074@isec.pt


#define SAUDAVEL 'S'
#define DOENTE 'D'
#define IMUNE 'I'
#define RECUPERADO 'R'
#define MORTO 'M'
#define MAX_NAME 20 
#define SEM_LOCAL 0
#define MAX_BACK 3

int Config;
int Iteracao;


typedef struct sala local, *plocal;
typedef struct Pessoa pessoa, *ppessoa;
typedef struct Simulacao simulacao, *psimulacao; 
typedef struct Backup backup, *pbackup;


struct sala{
    int id;
    int capaciadade;
    int liga[3];
};


struct Pessoa{
    char identificador[MAX_NAME];
    int idade;
    char estado;
    int dias; //Se DOENTE, n de dias infetado
    int local;  // se -1 nao se encontra em nenhum local
    ppessoa prox;
};


struct Simulacao{
    local l;
    psimulacao prox;
    ppessoa listaP;
    int nPessoas;
};

