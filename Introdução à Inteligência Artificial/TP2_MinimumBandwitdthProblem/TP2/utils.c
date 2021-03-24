#include "utils.h"

// Leitura do ficheiro de input
// Recebe: nome do ficheiro, numero de vertices (ptr), numero de arestas (ptr)
// Devolve a matriz de adjacencias
int* init_dados(char *nome, int *v, int *are)
{
    FILE *f;
    int *p,*q;
    int i, j;
    char lixo[100]; //Esta variável vai guardar a primeira linha do ficheiro aka o comentário

    f=fopen(nome, "r");
    if(!f)
    {
        printf("Erro no acesso ao ficheiro dos dados\n");
        exit(1);
    }
    fscanf(f,"%99[^\n]", lixo); // Recolhe o comentário
    fscanf(f, "%d %d %d[^\n]",v , v, are); // Recolhe num de vertices e arestas


    // Alocacao dinamica da matriz
    p = malloc(sizeof(int)*(*are)*(*are));
    if(!p)
    {
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }
    q=p;

    //Preenche matriz d adjacencias
    for(i=0; i<*are; i++)
    {
        for(j=0; j<2; j++)
            fscanf(f, "%d", (p+(*are)*i+j));
    }


    printf("\nMatriz de Adj: ");
    for(i=0; i<*are; i++)
    {
        printf("  ");
        for(j=0; j<2; j++)
        {
            printf(" %d",*(q+(*are)*i+j));
        }
    }

    fclose(f);
    return q;
}




// Gera a solucao inicial
// Parametros: solucao, numero de vertices
// Devolve: solucao inicial de valores random nao repetidos
void gera_sol_inicial(int *sol, int v)
{
    /*
    sol[0]=3;
    sol[1]=1;
    sol[2]=2;
    sol[3]=5;
    sol[4]=4;*/

    int i, x, status;

    for (i = 0; i < v; i++)
    {
        do
        {
            sol[i] = random_l_h(1,v);
            status = 1;

            for( x = 0; (x < i) && (status==1); x++ )
            {
                if(sol[i]==sol[x])
                    status=0;

            }

        }
        while(status==0);
    }


}


// Escreve solucao
// Parametros: solucao e numero de vertices
void escreve_sol(int *sol, int vert)
{
    int i;

    printf("\nSolucao: ");
    for (i = 0; i < vert; i++)
        printf("%d  ", sol[i]);
}



// copia vector b para a (tamanho n)
void substitui(int a[], int b[], int n)
{
    int i;
    for(i=0; i<n; i++)
        a[i]=b[i];
}

// Inicializa o gerador de numeros aleatorios
void init_rand()
{
    srand((unsigned)time(NULL));
}

// Devolve valor inteiro aleatorio entre min e max
int random_l_h(int min, int max)
{
    return min + rand() % (max-min+1);
}

// Devolve um valor real aleatorio do intervalo [0, 1]
float rand_01()
{
    return ((float)rand())/RAND_MAX;
}




int txtOptions(){
    int i;
    puts("\nEscolha txt:");
    puts("1 - inst_teste.txt" );
    puts("2 - bcspwr01.txt");
    puts("3 - bcspwr02.txt");
    puts("4 - bcspwr03.txt");
    puts("5 - will199.txt");
    puts("6 - dwt234.txt");
    puts("Opcao: ");
    do {
        scanf("%d", &i);
    } while (i < 1 || i >= 7 );

    return i;
}


int algOptions(){
    int i;
    puts("\nEscolha Algoritmo:");
    puts("1 - Trepa Colinas");
    puts("2 - Recritalizacao");
  //  puts("4 - Evolutivo");
  //  puts("5 - Hibrido");
    puts(" Opcao: ");
    do {
        scanf(" %d", &i);
    } while (i < 1 || i >= 3);

    return i;
}

