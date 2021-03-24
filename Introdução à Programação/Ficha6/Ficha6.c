//Introdução à Programação - Ficha Laboratorial 6

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#define N 5



/*F6 E01--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
array[N] - array de N elementos inteiros

RESULTADOS PRETENDIDOS:
media(float) - media dos elementos presentes no array

CONHECIMENTO REQUERIDO:
media=soma/nElementos

ESTRATÉGIA:
Repetir este processo ate que ao maximo da capacidade do array:
    Obter elemento do array.
    Somar.
Repetir este processo ate que ao maximo da capacidade do array:
    Mostrar elemento do array.
Fazer a media dos elementos do array.
Mostrar a media.


--PSEUDOCODIGO--

INICIO"programa media"
    soma<-0
    media<-0
    aux<-0

    PARA(a=0; a<N; a++) FAZER
        OBTEM(aux)
        array[a]<-aux
        soma<-soma+array[a]
    FIM PARA

    PARA(b=0; b<N; b++) FAZER
        MOSTRA(array[b])
    FIM PARA

    media=soma/N
    MOSTRA(media)
FIM"programa media"

*/
int main0601(){
    int a, b, array[N], aux=0, soma=0;
    float media=0;


    printf("-----Calculadora de Medias-----");
    printf("\n\nInsira os numeros pretendidos:\n");
    for(a=0; a<N; a++){
        scanf("%d", &aux);
        array[a]=aux;
        soma=soma+array[a];
    }

    printf("\n\nArray de numeros inserido:  ");
    for(b=0; b<N; b++){
        printf("%d  ",array[b]);
    }

    media=soma/N;
    printf("\n\nMedia Calculada: %0.2f\n\n", media);

}

/*F6 E02--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
array[N] (inteiros) - array de N elementos inteiros

RESULTADOS PRETENDIDOS:
media(float) - media dos elementos presentes no array
array[N] (inteiros) - array[N] de inteiros inserido mas com os
elementos menores que a media, a zero.

CONHECIMENTO REQUERIDO:
media=soma/nElementos

ESTRATÉGIA:
Repetir este processo ate que ao maximo da capacidade do array:
    »Obter elemento do array.
    »Somar.
Repetir este processo ate que ao maximo da capacidade do array:
    »Mostrar elemento do array.
Fazer a media dos elementos do array.
Mostrar a media.
Repetir este processo ate que ao maximo da capacidade do array:
    »Se array[i]<media
    »Então array[i]==0
Repetir este processo ate que ao maximo da capacidade do array:
    »Mostrar elemento do array.(alterado ou não)

--PSEUDOCODIGO--

INICIO"programa media"
    soma<-0
    media<-0
    aux<-0

    PARA(a=0; a<N; a++) FAZER
        OBTEM(aux)
        array[a]<-aux
        soma<-soma+array[a]
    FIM PARA

    PARA(b=0; b<N; b++) FAZER
        MOSTRA(array[b])
    FIM PARA

    media=soma/N
    MOSTRA(media)

    PARA(c=0; c<N ;c++)FAZER
        SE(array[c]<media)
            array[c]=0;
    FIM PARA

    PARA(d=0; d<N; d++) FAZER
        MOSTRA(array[d])
    FIM PARA

FIM"programa media"

*/
int main0602(){
    int a, b, c, d, array[N], aux=0, soma=0;
    float media=0;


    printf("-----Calculadora de Medias-----");
    printf("\n\nInsira os numeros pretendidos:\n");
    for(a=0; a<N; a++){
        scanf("%d", &aux);
        array[a]=aux;
        soma=soma+array[a];
    }

    printf("\n\nArray de numeros inserido:  ");
    for(b=0; b<N; b++)
        printf("%d  ",array[b]);

    media=soma/N;
    printf("\n\nMedia Calculada: %0.2f\n", media);

    for(c=0; c<N; c++){
        if(array[c]<media)
            array[c]=0;
    }

    printf("\nArray alterado:  ");
    for(d=0; d<N; d++){
        printf("%d  ",array[d]);
    }

    printf("\n\n");
    return 0;
}

/*F6 E03 - Comparação de conjuntos--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:

--PSEUDOCODIGO--
*/
int main0603(){
    int conjA[10]={0,1,2,3,4,5,6,7,8,9}, conjB[10], final[10];
    int opcao, a ,b ,c, i ;

    printf("\nInsira o conjunto a comparar: ");
    for(a=0; a<10 ; a++){
        scanf("%d", conjB[a]);
    };


    printf("\n\nComparacao de conjuntos: ");
    for(b=0; b<10; b++){
        if(conjA[b]==conjB[b])
            final[b]==1;
        else
            final[b]==0;
    }

}


/*F6 E03  MAL-------------------------------------------------------------------
*/

void MostraVetor(double a[], int m){
    int i;

    for(i=0; i<m; i++)
        fprintf(stdout, " %0.2lf ", a[i]);

    fprintf(stdout, "\n");}

void Reuniao(int a[], int b[], int n, int r[]){
    int i;

    for(i=0; i<n; i++)
        if(a[i] || b[i])
            r[i]=1;
        else
            r[i]=0;

    return;
}

void Intersecao(int a[], int b[], int n, int i[]){
    int p;

    for(p=0; p<n;p++)
        if(a[p] && b[p])
            i[p]=1;
        else
            i[p]=0;

    return;
}

void Diferenca(int a[], int b[], int n, int d[]){
    int i;

    for(i=0; i<n; i++)
        if(a[i] && !b[i])
            d[i]=1;
        else
            d[i]=0;

    return;
}

void main()
{
    int a[N]={1,0,0,0,1,1,0,0,0,1};
    int b[N]={1,0,0,0,0,0,0,0,0,1};
    int c[N];

    MostraVetor(a,N);
    MostraVetor(b,N);

    Reuniao(a,b,N,c);
    MostraVetor(c,N);

    Intersecao(a,b,N,c);
    MostraVetor(c,N);

    Diferenca(a,b,N,c);
    MostraVetor(c,N);
}

/*F6 E04--------------------------------------------------------------------
*/





