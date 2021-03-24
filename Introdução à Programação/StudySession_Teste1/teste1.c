//StudySession - Novembro 2017

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>


/*F1 E02--------------------------------------------------------------------

--PSEUDOCODIGO--

INICIO<programa>
	OBTEM (nota1)
	OBTEM(nota2)
	Notafinal=(nota1+nota2)/2
	MOSTRA ( notafinal )
FIM<programa>


*/
int main02(){
    float nota1, nota2, notafinal;

    printf("Insira nota1:\n");
    scanf("%f", &nota1);
    printf("Insira nota2:\n");
    scanf("%f", &nota2);

    notafinal=(nota1+nota2)/2;
    printf("Nota final: %f", notafinal);

    return 0;
}



/*--F1 E22-------------------------------------------------------------------


--MAPA DE ANALISE DO PROBLEMA--

DADOS DE ENTRADA:
d (inteiro) dia atual
m (inteiro) mes atual
a (inteiro) ano atual

RESULTADOS PRETENDIDOS:
d (inteiro) dia da data do dia seguinte
m (inteiro) mes da data do dia seguinte
a (inteiro) ano da data do dia seguinte

CONHECIMENTO REQUERIDO:
meses com 30dias: 4-abril 6-abril 9-setembro 11-novembro

ESTRATÉGIA: Obter d, m, ,a. Se for o ultimo dia do ano, passa para o
 primeiro dia do ano seguinte. Se for o ultimo dia do mes, passa para o
 primeiro dia do mes seguinte. Se não for nenhuma das hipoteses anteriores,
 passar para o dia seguinte desse mês.
 Mostrar d , m, a.



 ser fim do ano
 ser fim do mes com 28
 ser fim so mes com 30
 ser fim do mes com 31


 --PSEUDOCODIGO COM IF--

    INICIO " DiaSeguinte "
    OBTEM ( d, m, a)
    SE (d==31 && m==12) ENTÃO
        a++;
        d==1;
        m==1;
        SENÃO
            SE (d==31 OU (d==30 E (m==4 OU  m==6 OU m==9 OU m==11)) ENTAO
            m++;
            d==1;
            SENÃO
                d++;
            FIM SE
        FIM SE
    FIM SE
*/
int main22(){
    int d, m, a;

    SetConsoleOutputCP(1252);   //para a consola portuguesa funcionar

    printf("\nIntroduza da data atual: (dia.mês.ano))\n");
    scanf("%d %d %d", &d ,&m, &a);

    if (d==31 && m==12)
    {
        a++;
        d=1;
        m=1;
    }
    else
    {
        if ( (d==28 && m==2) || (d==29 && m==2)
             || (d==30 && (m==4 || m==6 || m==9 || m==11))
             || (d==31)
            )
            {
                m++;
                d=1;
            }
            else
                d++;

    }

    printf("\n\nData do dia seguinte:\n %d.%d.%d", d, m, a);
    return 0;
}



/*F1 E26 ------------------------------------------------------------------------



----TABELA DE ANALISE DO PROBLEMA----

DADOS DE ENTRADA:
base(real) - Número de Base
expoente (inteiro) - Número do expoente

RESULTADOS PRETENDIDOS:
resultado (real) - Resultado de base ^expoente

CONHECIMENTO ADQUIRIDO:

ESTRATÉGIA:
Obter a base e o expoente.
Fazer expoente multiplicações de base e guardar em resultado.
Mostrar o resultado.

estrategia aconselhada -> usar for


----PSEUDOCÓDIGO----

INICIO programa
    resultado <- 1
    contador <- 0
    OBTEM (base, expoente)
        ENQUANTO (contador< expoente )FAZER
            resultado <- resultado * base
            contador <- contador + 1
        FIM ENQUANTO
        MOSTRA (resultado)
FIM programa


*/
void main26(){
    float resultado=1, base, contador=0;
    int expoente;

    printf("Insira a base e o expoente: \n");
    scanf("%f %d", &base, &expoente);

    while (contador < expoente)
    {
        resultado = resultado * base;
        contador ++;
    }

    printf(" Resultado: %.2f\n", resultado);

    return 0;
}




/*F1 E29--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
peso (float) -> peso de cada individuo

RESULTADOS PRETENDIDOS:
media (float) -> media dos pesos das pessoas com mais de 60kg
maiorpeso (float) -> maior peso inserido do grupo de pesos menores que 60kg

CONHECIMENTO REQUERIDO:
media = soma dos elementos / numero de elementos

ESTRATÉGIA: Obter um peso. Se for maior do que 60kg, somar e fazer a média.
Se for menor do que 60kg, verificar se é o maior valor. Continuar o processo
até ser obtido um valor negativo. Por fim, mostar a media e o maiorpeso.


--PSEUDOCODIGO--
INICIO balanca
    soma <- 0
    contador <-0
    media <- 0
    maiorpeso <- 0
    ENQUANTO (peso > 0 ) FAZER
        OBTEM (peso)
            SE (peso > 60) ENTAO
                soma <- soma + peso
                contador++;
            SE NÃO
                SE (peso > peso maior) ENTAO
                    pesomaior <- peso;
                FIM SE
            FIM SE
    FIM ENQUANTO
    media <- soma / contador
    MOSTRA ( media, pesomaior )
FIM balanca


*/
int main29(){
    float peso, maiorpeso=0, soma=0, media=0;
    int contador=0;

    while(peso>0){
        printf("\nInserir peso:");
        scanf("%f", &peso);
        if(peso>60){
            soma = soma + peso;
            contador++;
        }
        else{
            if(peso>maiorpeso)
                maiorpeso=peso;
        }
    }
    media = soma/contador;
    printf("\n\nMedia (>60kg) : %0.2f \nMaior Peso (<60kg) : %0.2f", media, maiorpeso);
    }



/*F1 E32--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
num (inteiro) -> numero

RESULTADOS PRETENDIDOS:
soma (inteiro) -> soma dos algarismos do num introduzido

CONHECIMENTO REQUERIDO:
Os dígitos de um número inteiro são obtidos efectuando
sucessivas divisões por 10

ESTRATÉGIA:
Obtem-se o numero inteiro. Fazem-se divisoes sucessivas por 10 até
o resultado ser zero. Somam-se todos os resultados e apresenta-se no ecran.


--PSEUDOCODIGO--
INICIO CalculadoraAlgarismos
    div<-0
    soma<-0
    OBTEM(num)
        ENQUANTO(num>0)FAZER
            div<-num%10
            soma<-soma+div
            num<-num/10
        FIM ENQUANTO
    MOSTRA(soma)
FIM CalculadoraAlgarismos

*/
int main132(){
    int num, div=0, soma=0;

    printf("\n\n----------Calculadora de Algarismos----------");
    printf("\nInsira o numero pretendido:     ");
    scanf("%d", &num);

     while (num>0)
     {
         div=num%10;
         soma=soma+div;
         num=num/10;
     }

    printf("\n\nSoma dos algarismos: %d\n\n",soma);
    return 0;
}


/*F1 E35--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main135 (){ //SOMATÓRIO, NAO PERCEBI, NÃO SEI RESOLVER SOMATORIOS

    int a, b, c, d, e, f, s, i, y, j;
    s=0;

    printf("Insira a b c d e f:\n");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    while ( a<0 || c<0 || e<0 || b<a || c<d || e<f )
    {
        i=a;
        while (i<=b)
        {
            i=c;
            while (i<=d)
            {
                y=e;
                while (y<=e)
                {
                    s=s+i*j*y;
                    y=y+1;
                }
                j++;
            }
            i++;
        }
    printf("Resultado do somatorio triplo:%d", s);
    }

}



/*F3 E04--------------------------------------------------------------------

--MAPA DE ANÁLISE DO PROBLEMA--

DADOS DE ENTRADA: x e y (real) - Coordenada x e y do plano
RESULTADOS PRETENDIDOS: msg - Mensagem a dizer onde pertence o ponto indicado
CONHECIMENTO REQUERIDO: --
ESTRATÉGIA: Pedir ao utilizador um ponto na forma de par ondenado e em
alternativa avalisar os valores de x e de y. Dessa forma se x e y forem 0,
escrever que o ponto pertence à origem. Em alternativa se x é zero e y não,
indica que pertence ao eixo e vice versa. Se x e y positivos, o ponto pertence
ao 1*quadrante. Se x positivo e y negativo, pertence ao 4* quadrante. O ponto
pertence ao 2* quadradrante se x for negativo e y negativo. Por fim o ponto
pertence ao 3* quadrante se ambos x e y forem negativos.


--PSEUDOCODIGO--

    INICIO quadrantes
    OBTEM (x, y)
    SE (x=0 & y=0) ENTAO
        msg <- "Origem"
    SENAO
        SE (x=0 E y!=0) ENTAO
            msg <- "Eixo dos YY"
        SENAO
            SE(x=!0 E y==0) ENTÃO
                msg <- "Eixo dos XX"
            SENÃO
                SE( x>0 && y>0) ENTAO
                    msg <- 1*Quadrante
                SENAO
                    SE (x>0 && y<0) ENTAO
                        msg <- 4ºQuadrante
                    SENAO
                        SE (x<0 && y>0) ENTÃO
                            msg <- 2*Quadrante
                        SENAO
                            msg <- 3*Quadrante
                        FIM SE
                    FIM SE
                FIM SE
            FIM SE
        FIM SE
    FIM SE
FIM quadrantes



*/
int main04(){
    int x, y;

    printf("\n------- Plano Cartesiano: -------\n");
    printf("\nInsira as coordenadas do Ponto:\n");
    scanf("%d %d", &x, &y);

 if (x==0 && y==0)
    {
        printf("\nPonto ( %d , %d ) - > Pertence à origem",x,y);
    }
    else
    {
        if(x==0 && y!=0)
            printf("\nPonto ( %d , %d ) - > Pertence ao eixo dos YY.\n\n", x,y);
        else
        {
            if (x!=0 && y==0)
                printf("\nPonto ( %d , %d ) - > Pertence ao eixo dos XX.\n\n",x,y);
            else
            {
                if (x>0 && y>0)
                    printf("\nPonto ( %d , %d ) - > Pertence ao 1*quadrante.\n\n",x,y);
                else
                {
                    if (x>0 && y<0)
                        printf("\nPonto ( %d , %d ) - > Pertence ao 4*quadrante.\n\n",x,y);
                    else
                    {
                        if(x<0 && y>0)
                            printf("\nPonto ( %d , %d ) - > Pertence ao 2*quadrante.\n\n",x,y);
                        else
                            printf("\nPonto ( %d , %d ) - > Pertence ao 3*quadrante.\n\n",x,y);
                    }
                }
            }
        }
    }
}



/*F3 E10 /c IF ELSE --------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
d (inteiro) dia atual
m (inteiro) mes atual
a (inteiro) ano atual

RESULTADOS PRETENDIDOS:
d (inteiro) dia da data do dia seguinte
m (inteiro) mes da data do dia seguinte
a (inteiro) ano da data do dia seguinte

CONHECIMENTO REQUERIDO:
mes com 28 dias: 2-fevereiro
meses com 30dias: 4-abril 6-junho 9-setembro 11-novembro
meses com 31 dias: 1-janeiro 3-marco 5-maio 7-julho 8-agosto 10-setembro 12-Dezembro

ESTRATÉGIA:


--PSEUDOCODIGO--
    INICIO DiaSeguinte
        OBTEM ( d, m, a)
        SE (d==31 && m==12) ENTAO
            a++;
            d<-1
            m<-1;
        SE NÃO
            SE ( (d==28 && m==2) || (d==29 && m==2)
             || (d==30 && (m==4 || m==6 || m==9 || m==11))
             || (d==31) ) ENTAO
                m++;
                d<-1;
            SE NAO
            d++;
            FIM SE
        FIM SE
        MOSTRA(d, m, a);
    FIM DiaSeguinte
*/
int main10(){
    int d, m, a;

    SetConsoleOutputCP(1252);   //para a consola portuguesa funcionar

    printf("\nIntroduza da data atual: (dia.mês.ano))\n");
    scanf("%d %d %d", &d ,&m, &a);

    if (d==31 && m==12)
    {
        a++;
        d=1;
        m=1;
    }
    else
    {
        if ( (d==28 && m==2) || (d==29 && m==2)
             || (d==30 && (m==4 || m==6 || m==9 || m==11))
             || (d==31)
            )
            {
                m++;
                d=1;
            }
            else
                d++;

    }

    printf("\n\nData do dia seguinte:\n %d.%d.%d", d, m, a);
    return 0;
}



/*F3 E10 /c SWITCH CASE--------------------------------------------------------------------


DADOS DE ENTRADA:
d (inteiro) dia atual
m (inteiro) mes atual
a (inteiro) ano atual

RESULTADOS PRETENDIDOS:
d (inteiro) dia da data do dia seguinte
m (inteiro) mes da data do dia seguinte
a (inteiro) ano da data do dia seguinte

CONHECIMENTO REQUERIDO:
mes com 28 dias: 2-fevereiro
meses com 30dias: 4-abril 6-junho 9-setembro 11-novembro
meses com 31 dias: 1-janeiro 3-marco 5-maio 7-julho 8-agosto 10-setembro 12-Dezembro

ESTRATÉGIA:


--PSEUDOCODIGO--

INICIO DiaSeguinte
    OBTEM (d,m,a)
    QUANDO (d)
        CASO 28:
            QUANDO (m)
                CASO 2:
                    d <- 1
                    m++
            FIM QUANDO
        CASO 30:
            QUANDO (m)
                CASO 4:
                CASO 6:
                CASO 9:
                CASO 11:
                    d <- 1
                    m++
            FIM QUANDO
        CAS0 31:
            QUANDO (m)
                CASO 12:
                    d <- 1
                    m <- 1
                    a++
            FIM QUANDO
        DEFAULT:
        d++
    FIM QUANDO
    MOSTRA (d,m,a)
FIM DiaSeguinte


*/
int main310(){
     int d, m, a;

    SetConsoleOutputCP(1252);   //para a consola portuguesa funcionar

    printf("\nIntroduza da data atual: (dia.mês.ano))\n");
    scanf("%d %d %d", &d ,&m, &a);

    switch(d){

    case 28:
        switch(m){
        case 2:
            d=1;
            m++;
        } break;

    case 30:
        switch(m){
        case 4:
        case 6:
        case 9:
        case 11:
            d=1;
            m++;
        } break;

    case 31:
        switch(m){
        case 12:
            d=1;
            m=1;
            a++;

        } break;
    default:
        d++;

    }

    printf("\n\nData do dia seguinte:\n %d.%d.%d\n\n", d, m, a);
    return 0;
}




/*F4 E03--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
preco (real) -> preco do produto
tp (char) -> tipo de produto

RESULTADOS PRETENDIDOS:
numAlimentar (inteiro) -> numero de produtos do tipo alimentar
numOutros (inteiro) -> numero de produtos do tipo não alimentar
numTotal (inteiro) -> numero total de produtos
totalSemIva (real) -> preco total sem iva
totalComIva (real) -> preco total com iva

CONHECIMENTO REQUERIDO:
produtos alimentares -> iva de 6%
produtos não alimentares -> iva de 23%

ESTRATÉGIA:
    Repetir os seguintes processos até ser introduzido um preço nulo ou
negativo: Obter o preço do procuto. Se o preço for positivo, obter o tipo
de produto (válido!). Caso o tipo de produto seja A ou a, incrementa-se o
numero de produtos alimentares e soma-se o preço desse produto com iva de
6% para se obter o total de preços com iva. Caso o tipo de produto seja O
 ou o, incrementa-se o numero de produtos  não alimentares e soma-se o
 preço desse produto com iva de 23% para se obter o total de preços com iva.
 Por fim, calcula-se o preco sem iva somando o preco ao total de precos sem
 iva e também é calculado o numero total de produtos, somando o numero de
 produtos alimentares com o numero de produtos não alimentares.




--PSEUDOCODIGO--

INICIO supermercado
    numAlimentares<-0
    numOutros<-0
    numTotal<-0
    totalSemIva<-0
    totalComIva<-0

    FAZER
        OBTEM(preco)
        SE (preco > 0) ENTAO

            FAZER
                OBTEM (tp)
            ENQUANTO(tp!='a' e tp!='A' e tp!='o' e tp!='O')

            CASO (tp)
                QUANDO (tp 'a' ou 'A')
                    numAlimentos <- numAlimentos + 1
                    totalComIva <- totalComIva + (preco*0.06)
                QUANDO (tp 'o' ou 'O')
                    numOutros <- numOutros + 1
                    totalComIva <- totalComIva + (preco*0.23)
            FIM CASO

            numTotal<-numAlimentares+numOutros
            totalSemIva <- totalSemIva + preco

        FIM SE
    ENQUANTO ( preco > 0)

    MOSTRA(numAlimentos, numOutros, totalSemIva, totalComIva)
FIM supermercado
*/

int main303(){
    int numAlimentares=0, numOutros=0, numTotal=0;
    float preco, totalSemIva=0, totalComIva=0;
    char tp;

    SetConsoleOutputCP(1252);
    printf("--------------- Caixa Registadora ---------------\n\n");
    printf("Produto Alimentar: A\nProduto Não Alimentar: O\n\n");


    do{
        printf("\nPreço do Produto:     ");
        scanf("%f",&preco);

        if(preco>0){

            do {
                printf("\nTipo de Produto:      ");
                scanf("%c",&tp);

            }while(tp!='a' && tp!='A' && tp!='o' && tp!='O');

            switch(tp){
                case 'a':
                case 'A':
                    numAlimentares++;
                    totalComIva+=preco+(preco*0.06);
                    break;
                case 'o':
                case 'O':
                    numOutros++;
                    totalComIva+=preco+(preco*0.23);
                    break;
            }
            numTotal=numAlimentares+numOutros;
            totalSemIva+=preco;
        }


    }while(preco>0);


    printf("\n\n\n--------------- Totais ---------------");
    printf("\nProdutos Alimentares: %d\nProdutos Não Alimentares: %d\nTotal de Produtos: %d",numAlimentares,numOutros,numTotal);
    printf("\nTotal Sem Iva: %f\nTotal com Iva: %f\n\n", totalSemIva, totalComIva);
}



/*F4 E09--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
ele (inteiro) -> elementos da sequencia

RESULTADOS PRETENDIDOS:
maxi (inteiro) -> numero maximo da sequencia
pos (inteiro) -> posição do numero maximo da sequencia
tam (inteiro) -> tamanho da sequencia

CONHECIMENTO REQUERIDO:

ESTRATÉGIA:
Repetir os seguintes processos:
    Obter um numero.
    Verificar se é o maior.
    Se for o maior, verificar a sua posição.
Terminar os preocessos quando é inserido zero.
Mostrar o numero maximo, a sua posicao e o numero de elementos da sequencia.



--PSEUDOCODIGO--
INICIO sequencia
    maxi <-0
    pos <-0
    tam <-0

    FAZER
        OBTEM (ele)
        tam++;
        SE(ele==maxi)
            ele<-maxi;
            pos<-tam;
        FIM SE

    ENQUANTO (ele!=0)
    MOSTRA(max,pos,tam)
FIM sequencia


*/
int main409(){
    int ele, maxi=0, pos=0, tam=0;

    do{
        printf("Insira um Numero:   ");
        scanf("%d", &ele);
        tam++;

        if (ele>maxi){
            maxi=ele;
            pos=tam;
        }

    }while(ele!=0);

    printf("\n\nMaximo: %d  Surgiu na posicao: %d   Tamanho da sequencia: %d", maxi ,pos ,tam-1);

}




/*F4 E10--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
ele (real) -> elemento da sequencia

RESULTADOS PRETENDIDOS:
soma (real) -> soma de numeros da sequencia
media (real) -> media dos numeros da sequencia

CONHECIMENTO REQUERIDO:


ESTRATÉGIA:
Repetir os processos: Obter elemento da sequencia e verificar se está
por ordem crescente de acordo com a sequencia.
Se sim, calcular a soma e a media, se não, terminam os processos. Por fim
mostrar a soma e a media.

--PSEUDOCODIGO--

INICIO sequencia
    eleAnterior <- -10000
    soma <-0
    media <-0
    cont <-0

    FAZER
        cont++
        soma<-soma+ele
        eleAnterior<-ele;
        OBTEM(ele)
    ENQUANTO (eleAnterior<ele)

    media<-soma/cont
    MOSTRA(soma,media)
FIM sequencia

*/
int main410(){
    float ele, eleAnterior=-100000, soma=0, media=0;
    int cont=0;

    printf("\n\n--------------Sequencia--------------\n\n");

    printf("\nInsira um elemento da sequencia:    ");
    scanf("%f", &ele);


      do {

        cont++;
        soma+=ele;
        eleAnterior=ele;

       printf("\nInsira um elemento da sequencia:    ");
        scanf("%f", &ele);

    } while(eleAnterior<ele);

    media=soma/cont;

    printf("\n\n--------------Resultados--------------\n\n");
    printf("Soma: %0.1f        Media: %0.2f\n\n\n", soma, media);

    return 0;
}



/*F4 E11--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
nota1 (real) -> nota da prova 1
nota2 (real) -> nota da prova 2
faltas (inteiro) -> faltas dadas pelo aluno

RESULTADOS PRETENDIDOS:
aprov (inteiro) -> numero de alunos aprovados
reprov (inteiro) -> numero de alunos reprovados
notafinal (real) -> nota final de cada aluno
mediaturma (real) -> media das notas da turma

CONHECIMENTO REQUERIDO:
reprova se:
    -> media das 2 provas <10
    -> faltou mais de 25%

ESTRATÉGIA:
Repetir os processos para os 12 alunos: Obter nota de aluno, verificar
se tem as presenças necessarias. Se sim, calcula-se a sua notal final.
Se não o aluno está automáticamente reprovado.
Por fim, mostrar a media das notas finais da turma.

--PSEUDOCODIGO--

INICIO classificacao
    cont<-0
    soma<-0
    media<-0

    FAZER
        OBTEM(nota1,nota2,faltas)

        SE (faltas>=50*0.25) ENTAO
            MOSTRA(reprovou)
        SE NÃO
            notafinal<-(nota1+nota2)/2
            MOSTRA(notafinal)
            SE (notafinal>=9,5)ENTAO
                cont++;
                soma<-soma+notafinal;
            FIM SE
        FIM SE

        media<-soma/cont
        MOSTRA(mediaturma)
    ENQUANTO (a>13)

FIM classificacao
*/
int main(){
    int cont=0, faltas, a=1;
    float soma=0, media=0, nota1, nota2, notafinal=0, mediaturma=0;
    printf("\n\n----------Resultados da Turma----------\n");

    do {

        printf("\n---Aluno %d---",a++);
        printf("\nNota 1: ");
        scanf("%f", &nota1);
        printf("Nota 2: ");
        scanf("%f", &nota2);
        printf("Faltas: ");
        scanf("%d", &faltas);

        if(faltas>=50*0.25)
            printf("-->Reprovado!");
        else {
            notafinal=nota1+nota2;
            if(notafinal>=9.5){
                cont++;
                soma+=notafinal;
                printf("-->Aprovado!");
            }
            else
                printf("-->Reprovado!");
        }

    } while(a!=13);

        mediaturma=soma/cont;
        printf("\n\n\n----------Media da turma: %f----------\n\n", mediaturma);

    return 0;
}
