//StudySession - Janeiro 2018

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#define C 100
#define TAM 5

//F01 E45-----------------------------------------------------------------
/*int divisores(int num){
    int div, cont=0;
    printf("\n----Divisores----\n");

    for(div=1; div<num+1; div++){
        if(num%div==0){
            printf("%d  ", div);
            cont++;
        }
    }
    printf("\n\n");
    return cont;
}

int main(){
    int n, i;

    printf("\nInsira os numeros pretendidos:\n (termine com zero)\n");
    do{
        scanf("%d",&n);
        if(divisores(n)==2)
            printf("------->O numero inserido e primo!\n\n");
        i++;
    }while(n!=0);

    printf("\n\n\nTerminou.\n\n\n");
}
*/


//F05 E01-----------------------------------------------------------------
/*int quadrado(int num){
    int q=0;
    q=num*num;
    return q;
}

int main(){
    int n, i;

    printf("\nInsira os numeros pretendidos:\n (termine com 0)\n\n ");

    do{
        scanf("%d",&n);
        if(n!=0)
            printf("-->Quadrado do numero: %d \n\n", quadrado(n));

    }while(n!=0);

    printf("\n\n\nTerminou.\n\n\n");
}
*/


//F05 E02-----------------------------------------------------------------
/*int verifica( int s, int i, int n){
    if( s<n && n<i )
        return 1;
    else
        return 0;
}

int main(){
    int sup, inf, num;

    printf("\n-------ESTAS A PASSAR DOS LIMITES?!?-------");
    printf("\nInsira o limite sup e inf pretendido:\n");
    scanf("%d %d", &sup , &inf);
    printf("\nInsira o numero a testar: ");
    scanf("%d", &num);

    if(verifica(sup, inf, num)==1)
        printf("\n-->Esta dentro do limite pretendido\n\n");
    else
        printf("\n-->Nao esta dentro do limite pretendido\n\n");

}
*/


//F05 E09-----------------------------------------------------------------
/*float proximo(float a, float b){
    float media=0, decimal=0;

    printf("\n\n-------Qual o mais proximo??------\n");
    media=(a+b)/2;
    printf("\nMedia: %f", media);
    decimal= media-(int)media; //tira a parte inteira e deixa a parte decimal do numero

    if(decimal>=0.5)
        printf("\nInteiro mais proximo da media: %d\n\n", (int)media+1 );
    else
        printf("\nInteiro mais proximo da media: %d\n\n", (int)media );
}

int main(){
    float numA, numB;

    printf("Insira dois reais:\n");
    scanf("%f %f", &numA, &numB);

    proximo(numA, numB);
}
*/


//F05 E13-----------------------------------------------------------------
/*int NovaAposta(int njogador){
    int aposta=0;

    printf("\n-----Nova Aposta-----\n");
    printf("E a vez do jogador %d!", njogador);
    printf("\nQual a sua aposta?");
    scanf("%d", &aposta);

    return aposta;
}

int compara(int pri, int seg){
    if (pri==seg)
        return 0;
    if (pri>seg)
        return 1;
    else
        return-1;
    }

int main(){
    int aleatorio ,jogada ,n, aposta;

    aleatorio= rand()%501; //define um numero aleatorio de 0 a 500

    printf("\n\n----Bem Vindo ao Jogo de Apostas!----\n\n");
    for(jogada=1; jogada!=0; jogada++)
    {
        if(jogada%2==0) //jogada par-> jogador 2 a jogar
            n=2;
        else
            n=1;

        aposta=NovaAposta(n);

        switch (compara(aleatorio,aposta)){
        case 0:
            printf("O jogador %d acertou!\n",n);
            ExitProcess(0);
            break;
        case 1:
            printf("O valor %d esta abaixo do numero certo\n",aposta);
            break;
        case -1:
            printf("O valor %d esta acima do numero certo\n",aposta);
            break;
        default:
            ExitProcess(0);
        }
    }
    return 0;
}
*/



//F05 E16-----------------------------------------------------------------
/*int caractere(char c){
    char carac;
    carac=toupper(c);
    switch (carac)
    {
    case 'A': return 1; break;
    case 'E': return 2; break;
    case 'I': return 3; break;
    case 'O': return 4; break;
    case 'U': return 5; break;
    default: return 0;
    }
}

int main(){
    char a;
    printf("\n\nInsira o caractere pretendido:");
    scanf("%c", &a);
    printf("\nOrdem: %d\n", caractere(a));
}
*/


//F06 E04-----------------------------------------------------------------
/*int compara(int *a, int *b, int tam){
    int i;

    for(i=0; i<tam; i++){
        if(a[i] != b[i])
            return 0;
    }
    return 1;
}

int main(){
    int pri[C], seg[C], t, i ,j ;

    printf("\n\n-------Comparacao de arrays-------\n");
    printf("\nDetermine o tamanho dos array's:  ");
    scanf("%d", &t);

    printf("\nConstrua o primeiro array a comparar:\n");
    for(i=0; i<t; i++)
        scanf("%d", &pri[i]);

    printf("\nConstrua o segundo array a comparar:\n");
    for(j=0; j<t; j++)
        scanf("%d", &seg[j]);

    if(compara==0)
        printf("\nOs array's sao diferentes\n\n");
    else
        printf("\nOs array's sao iguais\n\n");

}

*/


//F06 E05-----------------------------------------------------------------
/*int inverte(int num){
   int inv=0;

   do{
      inv=inv*10+(num%10);
      num=num/10;
    }while(num>0);

    return (inv);
}

void main(){
    int n;

    printf("Introduza o numero a verificar:\n");
    scanf("%d",&n);

    if(inverte(n)==n)
        printf("Capicua!\n");
    else{
        printf("Nao e Capicua!\n");
    }
}
*/


/*--F7 EX01-------------------------------------------------------------------

----MAPA DE ANALISE DO PROBLEMA----

DADOS DE ENTRADA:
frase(string) - array de caracteres terminda por \0

RESULTADOS PRETENDIDOS:
Frase com os caracteres por ordem inversa.

CONHECIMENTO REQUERIDO:
--

ESTRATÉGIA:
Obtem(frase)
ncar <- numero de caracteres da frase (tam da string)
Mostrar os caracteres um a um para a frente, isto é, começando no caracter
de posição ncar-1, ir decrementando o indice dessa posição até chegar ao indice 0.


 ----PSEUDOCODIGO----

    INICIO programa
        OBTEM (frase)
        i<- tamanho(frase)-1
        ENQUANTO (i>0)FAZER
            MOSTRA(frase[i])
            i<- i-1;
        FIM ENQUANTO
    FIM programa

*/
/*int main(){
    char frase[C], invert[C];
    int tam, i;

    printf("\n\n----------Invertidor----------\n");
    printf("\nInsira a frase a inverter:\n");
    gets(frase);

    printf("\nFrase Invertida: ");
    tam=strlen(frase);
    for(i=0; i<tam+1; i++){
        invert[i]=frase[tam-i];
        printf("%c", invert[i]);
    }

    return 0;
}


/*F07 E04--------------------------------------------------------------------
--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
frase (string) - array de caracteres terminada por /0

RESULTADOS PRETENDIDOS:
p(string) - palavra inicial da frase
rep(inteiro) - Numero de vezes que a palavra aparece na frase


CONHECIMENTO REQUERIDO:

ESTRATÉGIA:
Obtém(frase);
Encontrar a primeira palavra e guardar em p.
Contar quantas vezes a palavra aparece e mostrar.

--PSEUDOCODIGO--
*/
/*int main(){

    char frase[TAM], p[TAM], paux[TAM];
    int i=0, j=0, rep=1;

    printf("\n\nInsira a Frase:\n");
    gets(frase);

    strupr(frase); //Frase em maiusculas

    while(frase[i]!='\0' && frase==' ')
        i++;

    while(frase[i]!=' ')
    {
        p[j]=frase[i];
        i++;
        j++;
    }

    p[j]='\0'; //Torna o array numa string

    while(frase[i]!='\0')
    {
        while(frase[i]!='\0' && frase[i]==' ') //Retira os espaços no inicio das palavras
            i++;

        j=0;
        while(frase[i]!=' '&& frase[i]!='\0')
        {
            paux[j]=frase[i];
            i++;
            j++;
        }
        paux[j]='\0';
        if (strcmp(p,paux)==0)  //strcmp(compara strings) - se p e paux são iguais
            rep++;              // incrementa-se pre que é o numero de x que a palavra se repete
    }
    printf("\n A palavra repete-se %d vezes.", rep);

    return 0;
}*/



/*F07 E05--------------------------------------------------------------------



/*F07 E06--------------------------------------------------------------------

--ESPECIFICAÇÃO DA FUNÇÃO--

DADOS DE ENTRADA:
str (string) - Frase a alterar
len (int) - Tamanho da frase
e (char) - Caracter a duplicar

RESULTADOS PRETENDIDOS:
str (string) - Frase inicial alterada
altera (int) - 0 se a frase não foi a
lterada e 1 se foi

ESTRATÉGIA:
Receber(frase, len, e).
Ir copiando os caracteres da frase para um string auxiliar e sempre
que se encontrar o caracter e, repetir a sua introdução nessa string
auxiliar, até que se chegue ao fim da string (atenção não ultrapassar
 o tamanho da string inicial).
 Devolver altera, com valor respectivo.


*/
/*int modifica(char frase[], int tamanho, char caracter ){
    char fraseaux[TAM];
    int i=0, j=0;

    for(i=0, j=0; i<tamanho && j<TAM ; i++,j++)
    {
        fraseaux[j]=frase[i];
        if(fraseaux[i]==caracter)
        {
            j++;
            fraseaux[j]=caracter;
        }
    }

    fraseaux[j]='\0';
    strcpy(frase,fraseaux);

    if(j>i)
        return 1;
}
int main0706(){

    char str[TAM],c;

    printf("\n\nIntoduza a frase:\n");
    gets(str);
    printf("\n\nFrase Inicial: %s");

    printf("\n\nQual a letra que quer alterar?\n");
    c=getch();

    if(modifica(str,strlen(str),c)==1) //1 ou outro n* se for verdadeiro, 0 se for falso; ==1 pode ser ocultado
        printf("\n\nFrase Alterada: %s", str);
    else
        printf("\n\nA frase nao foi alterada.\n\n");

    return 0;
}*/



/*Exemplo
Programa que determina qual o valor máximo de uma sequência de
números inteiros introduzidos pelo utilizador (em que o valor zero
assinala o fim da sequência). Utiliza 2 funções: uma que obtém os
números do utilizador e outra que calcula o valor máximo dos números
introduzidos */
/*int LeNumeros(int n[],int dim){
    int i=0,cont=0;


    printf("\n\n-----Qual o maior numero da sequencia??-----\n");
    printf(" Numero: ");
    scanf("%d",&n[i]);

    while(n[i] && i<dim)
    {
        cont++;
        printf(" Numero: ");
        scanf("%d",&n[++i]);    //preenche o array
    }

    return cont;  //retorna no numero de numeros inseridos
}

int CalculaMaximo(int n[],int tam){
    int i,max;

    max=n[0]; //o maximo aqui é o que está na primeiro posiçao

    for(i=0;i<tam;i++) //enquanto se percorre o array
        if(n[i]>max)    // o conteudo da posição atual é maior do que o da posição anterior?
            max=n[i];      //se sim, entao o maximo passa a ser a posição atual

    return max;
}

void main()
{
    int numeros[C],tam;
    if((tam=LeNumeros(numeros,C))>0)
        printf("Valor maximo = %d\n",CalculaMaximo(numeros,tam));
    else
        printf("Nao foram introduzidos quaisquer numeros!\n");
}
*/


