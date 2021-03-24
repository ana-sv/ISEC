//Introdução à Programação - Ficha Laboratorial 1 //

/*F1 E00--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/

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



/*F1 E03--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
r (real) -> raio

RESULTADOS PRETENDIDOS:
a (real) -> area do circulo
p (real) -> perimetro do circula

CONHECIMENTO REQUERIDO:
pi = 3,14

ESTRATÉGIA:
Obter o raio do circulo e definir um valor aproximado para pi, ou seja, 3.14.
Calcular a area e perimetro do circulo através das formulas:
    p = 2*r*pi ;    a = r*r*pi ;
Por fim, mostrar a e p.


--PSEUDOCODIGO--

INICIO circulo
    a <- 0
    p <-
    pi <- 3.14
    OBTEM (raio)
    p <- 2*r*pi ;
    a <- r*r*pi ;
    MOSTRA (a, p)
FIM circulo

*/
void main03 (){
     float r, p, a, pi=3.14;
     printf("Escreva o raio do circulo: \n");
     scanf("%f", &r);
     p = 2*r*pi ;
     a = r*r*pi ;
     printf("PERIMETRO:%f \n AREA:%f ", p,a);

 }



/*F1 E04--------------------------------------------------------------------
--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
t1 ( real ) -> nota do teste 1
t2 ( real ) -> nota do teste 2
e ( real ) -> nota do exame

RESULTADOS PRETENDIDOS:
n (real) -> nota final

CONHECIMENTO REQUERIDO:

ESTRATÉGIA:
Obter os valore de t1, t2, e e somar.
Por fim, mostrar a nota final.


--PSEUDOCODIGO--
INICIO nota
    OBTEM (t1, t2, e)
    n <- t1 + t2 +e
    MOSTRA (n)
FIM nota



*/
 void main04 (){
     float t1, t2, e, n;
     printf("Insira a nota do teste1 (ate 2 valores):  \n");
     scanf("%f", &t1);
     printf("Insira a nota do teste2 (ate 2 valores): \n");
     scanf("%f", &t2);
     printf("Insira a nota do exame (ate 16 valores): \n");
     scanf("%f", &e);
     n=t1+t2+e;
     printf("Nota Final:%0.2f",n );

 }



/*F1 E05--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
numvendedor (inteiro) -> numero do vendedor
numcarros (inteiro) -> numero de carros vendidos pelo vendedor
sfixo (real) -> salario fixo do vendedor
vcarro (real) -> valor por carro vendido

RESULTADOS PRETENDIDOS:
numvendedor (inteiro) -> numero vendedor
vendas (real) -> valor total de vendas
smensal (real) -> salario mensal do vendedor

CONHECIMENTO REQUERIDO:
Comissão por cada carro vendido -> 5%
smensal = sfixo + comissoes

ESTRATÉGIA:
Obtem-se o numvendedor, sfixo, numcarros e vcarro.
Calcula-se vendas, comissao, smensal através das expressoes:
    vendas = numcarros * vcarro
    comissao = (vcarro * 0.05) * numcarros
    smensal = sfixo + comissao
Por fim, apresenta-se o numvendedor, vendas e smensal.

--PSEUDOCODIGO--

INICIO stand
    OBTEM (numvendedor, sfixo, numcarros, vcarro)
    vendas <- numcarros * vcarro
    comissao <- (vcarro * 0.05) * numcarros
    smensal <- sfixo + comissao
    MOSTRA (numvendedor, vendas, smensal)
FIM stand


*/
int main05(){

    int numvendedor, numcarros;
    float sfixo, vcarro, comissao, vendas, smensal;

    printf("\n----Calculadora de Salario Mensal:----\n");
    printf("\nNumero de Vendedor:    ");
    scanf("%d", &numvendedor);
    printf("Salario Fixo:     ");
    scanf("%f", &sfixo);
    printf("Numero de Carros Vendidos:    ");
    scanf("%d", &numcarros);
    printf("Valor por carro:    ");
    scanf("%f", &vcarro);

    vendas = numcarros * vcarro;
    comissao = (vcarro * 0.05) * numcarros;
    smensal = sfixo + comissao;

    printf("\n\n\n-----Resultados----");
    printf("\n\nNumero de Vendedor:%d \n\nTotal de Vendas:%f \n\nSalario Mensal:%f\n\n\n",numvendedor, vendas, smensal);


    return 0;
}



/*F1 E06--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
vbrancos (inteiro) - votos brancos
vnulos (inteiro) - votos nulos
vvalidos (inteiro) - votos validos

RESULTADOS PRETENDIDOS:
vtotal (inteiro) - total de votos
pvbrancos (real) - percentagem de votos brancos
pvnulos (real) - percentagem de votos nulos
pvvalidos (real) - percentagem de votos validos

CONHECIMENTO REQUERIDO: --

ESTRATÉGIA:
Obter o numeros dos diversos tipos de votos.
Calcular a percentagem de cada tipo em relação ao numero de votantes.
Por fim, apresentar os resultados pretendidos.


--PSEUDOCODIGO--

INICIO eleicao
    vtotal <- 0
    OBTEM(vbrancos, vnulos, vvalidos)
        vtotal <- vbrancos + vnulos + vvalidos;
        pvbrancos <- vbrancos*100 / vtotal
        pvnulos <- vnulos*100 / vtotal
        pvvalidos <- vvalidos*100 / vtotal
    MOSTRA (vtotal, pvbrancos, pvnulos, pvvalidos)
FIM eleicao

*/
int main06(){

    int vbrancos, vnulos, vvalidos, vtotal=0;
    float pvbrancos, pvnulos, pvvalidos;

    printf("Insira os votos brancos:\n");
    scanf("%d", &vbrancos);
    printf("Insira os votos nulos:\n");
    scanf("%d", &vnulos);
    printf("Insira os votos validos:\n");
    scanf("%d", &vvalidos);

    vtotal = vbrancos + vnulos + vvalidos;
    pvbrancos = vbrancos*100 / vtotal;
    pvnulos = vnulos*100 / vtotal;
    pvvalidos = vvalidos*100 / vtotal;

    printf("Total de Votos: %d \nVotos Brancos: %f \nVotos Nulos: %f \nVotos Validos: %f", vtotal, pvbrancos, pvnulos, pvvalidos);

}


/*F1 E07--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
kminicio (real) -> marcacao do conta km no inicio do dia
kmfim (real) -> marcacao do conta km no fim do dia
l (real) -> litros de combustivel gastos
valor (real) -> valor total recebido dos passageiros

RESULTADOS PRETENDIDOS:
media (real) -> media do consumo
lucro (real) -> lucro diário

CONHECIMENTO REQUERIDO:
Preço combustivel: 1.3€/litro -> pc (real)

ESTRATÉGIA:
Obter kminicio, kmfim, l e valor. Calcular km percorridos durante o dia
fazendo km = kmfim - kminicio. Calcular media e lucro através das
formulas: media = km/l e lucro = valor - (1*pc). Por fim, mostrar a
media e o lucro.

--PSEUDOCODIGO--

INICIO taxiManager
    OBTEM ( kminicio, kmfim, l, valor )
    km <- kmfim - kminicio
    media <- km/l
    lucro <- valor - (1*pc)
    MOSTRA ( media, lucro )
FIM taxiManager

*/
void main07 (){
    float kminicio, kmfim, km, l, valor, media, lucro, pc=1.3;

    printf("\n\n------------------Taxi Manager------------------\n\n");

    printf("Insira Km do inicio do dia:     ");
    scanf("%f", &kminicio);
    printf("\nInsira Km do fim do dia:      ");
    scanf("%f", &kmfim);
    printf("\nInsira os litros gastos:      ");
    scanf("%f", &l);
    printf("\nInsira o valor recebido:      ");
    scanf("%f",&valor);

    km = kmfim - kminicio;
    media = km/l;
    lucro = valor - (1*pc);

    printf("\n\n-----------------------------------------------\n");
    printf("\n\nMedia de consumo:%f\n", media);
    printf("\nLucro:%f\n\n\n",lucro);

}



/*F1 E08--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main08 (){
    float vb, ss, irs, vl;

    // vb = vencimento bruto
    // ss = seurança social
    // irs = IRS
    // vl = vencimento liquido

    printf("Insira o vencimento bruto:\n");
    scanf("%f", &vb);
    ss = vb * 0.11;
    irs = vb * 0.25;
    vl = vb - ss - irs;
    printf(" Para seguranca social:%f\n Para IRS:%f\n Vencimento liquido:%f\n", ss, irs, vl);
}



/*F1 E09--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main09 (){

    float kg, cp, vb, vt;

    // kg = kg de uvas recolhidas
    // cp = kg para consumo proprio
    // vb = producao de vinho branco
    // vt = producao de vinho tinto

    printf("Insira os Kg de uvas recolhidos:\n");
    scanf("%f", &kg);
    cp = kg * 0.25;
    vb = kg * 0.45;
    vt = kg * 0.30;
    printf("\n Kg para consumo proprio:%f\n Kg para producao de vinho branco:%f\n Kg para a producao de vinho tinto:%f\n", cp, vb, vt);


}



/*F1 E10--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main10 (){
 int t , h, m, s;
 printf("Insira o Tempo (segundos inteiros):\n");
 scanf("%d",&t);
 h = t/3600;
 m = (t-h*3600)/60;
 s = (t-h*3600)-(m*60);
 printf("\n %d = %dh %dm %ds", t, h, m, s);

}



/*F1 E11--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main11(){
    int d, pp, pd, pb;

    // d = dias de trabalho
    // pp = peças produzidas
    // pd = peças com defeito
    // pb = peças em bom estado;

    printf("Insira o numero de dias de trabalho:\n");
    scanf("%d", &d);
    pp = d*1300;
    pd = pp*0.13;
    pb = pp-pd;
    printf("Em %d dias de trabalho:\n Pecas produzidas:%d\n Pecas com defeito:%d\n Pecas em bom estado:%d\n", d, pp, pd, pb);

}



/*F1 E12--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main12 (){     //NÃO SEI SE ESTA CORRETOOOOOOOOOOOOOOO
    float a, b, c, x1, x2;
    printf("a=");
    scanf("%f", &a);
    printf("b=");
    scanf("%f", &b);
    printf("c=");
    scanf("%f", &c);
    if ( pow(b,2) -4*a*c >= 0 )
    {
        x1 = ( b+ sqrt( pow(b,2) +4*a*c ) )/2*a;
        x2 = ( b+ sqrt( pow(b,2) -4*a*c ) )/2*a;
        printf("x1=%f\n x2=%f\n", x1,x2);
    }
    else
        printf("Nao existem raizes reais");

}



/*F1 E13--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main13 (){
    int a, b, c, m;
    printf("Insira 3 numeros inteiros:\n");
    scanf("%d %d %d", &a, &b, &c);

    if (a>b)
    {
        if (a>c)
        printf("Maior numero:%d\n",a);
        else
        printf("Maior numero:%d\n",c);
    }
    else
        if (b>c)
        printf("Maior numero:%d\n",b);
        else
        printf("Maior numero:%d\n",c);

}



/*F1 E14--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main14(){
    float p, t, pIVA;

        // p = preço sem IVA
        // t = tipo de artigo
        // piva = preco com IVA

    printf("Insira o tipo de artigo:\n");
    scanf("%f", &t);
    printf("Insira o preco do artigo:\n");
    scanf("%f",&p);

    if (t==1)
        pIVA= p + p*0.05;
    else
    {
        if (t==2)
            pIVA= p + p*0.20;
        else
            pIVA= p + p*0.30;
    }
    printf("Preco do artico com IVA:%f\n", pIVA);
}


/*F1 E15--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main15 (){

    int nl, l, pr, area;
    printf("Insira o numero de lados (3 a 5)\n");
    scanf("%d", &nl);

    if (nl==3)
    {
        printf("Insira o tamanho do lado (inteiros)\n");
        scanf("%d",&l);
        pr=3*l;
        printf("TRIANGULO de perimetro %d\n", pr);
    }
    else
        if (nl==4)
    {
        printf("Insira o tamanho do lado (inteiros)\n");
        scanf("%d",&l);
        area=l*l;
        printf("QUADRADO de area %d\n", area);
    }
    else
        printf("PENTAGONO");
}



/*F1 E16--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main16 (){

    float N, n , r, a, s, d, m, op;

    //1=adição
    //2=subtracao
    //3=divisao
    //4=multiplicaçao
    //r=resultado

    printf("Introduza dois numeros\n");
    scanf("%f %f", &N, &n );
    printf("Indique a operacao:\n");
    scanf("%f", &op);
    r=0;

    if (op>1)
        r =N + n;


    printf("Reseultado da Operacao:%f", r);

}



/*F1 E17--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main17 (){
    float a, p;
    printf("Insira o peso do atleta:\n");
    scanf("%f", &p);
    printf("Insira a altura do atleta:\n");
    scanf("%f", &a);

    if (80>=p>=70)
        if (1.70>=a>=1.75)
        printf("Atleta Aceite\n");
        else
        printf("Atleta recusado por altura");
    else
        if (1.70>=a>=5551.75)
        printf("Atleta recusado por peso\n");
        else
        printf("Atleta recusado totalmente");
}


/*F1 E18--------------------------------------------------------------------

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

    INICIO quadrante
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


*/
int main18(){
    float x=0, y=0;

    SetConsoleOutputCP(1252);   //para a consola portuguesa funcionar

    printf("\n Insira o X e Y :\n ");
    scanf("%f %f", &x, &y);

    if (x==0 && y==0)
    {
        printf("Origem");
    }
    else
    {
        if(x==0 && y!=0)
            printf("\nPertence ao eixo dos YY.");
        else
        {
            if (x!=0 && y==0)
                printf("\nPertence ao eixo dos XX.");
            else
            {
                if (x>0 && y>0)
                    printf("\nPertence ao 1quadrante.");
                else
                {
                    if (x>0 && y<0)
                        printf("\nPertence ao 4ºquadrante.");
                    else
                    {
                        if(x<0 && y>0)
                            printf("\nPertence ao 2ºquadrante.");
                        else
                            printf("\nPertence ao 3ºquadrante.");
                    }
                }
            }
        }
    }
    return 0;
}


/*F1 E19--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
é triangulo se |a-b|<c  ou c<a+b

ESTRATÉGIA:
Obter a, b e c.


--PSEUDOCODIGO--
*/
void main19(){        //CORRIGIR
    float a, b, c;
    printf("Insira o comprimento das 3 linhas\n");
    scanf("%f %f %f", &a, &b, &c);

    if (a-b<c && c>0) // é suposto usar o modulo aqui mas eu não sei
        if (c<a+b)
        printf("Formam um triangulo\n");
        else
        printf("Nao formam um triangulo\n");
    else
    printf("Nao formam um triangulo\n");

}


/*F1 E20--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main20(){      //CORRIGIR
    float a, b, c;
    printf("Insira o comprimento das 3 linhas\n");
    scanf("%f %f %f", &a, &b, &c);

    if (a-b<c && c>0) // é suposto usar o modulo aqui mas eu não sei
        if (c<a+b)
        printf("Formam um triangulo\n");
        else
        printf("Nao formam um triangulo\n");
    else
    printf("Nao formam um triangulo\n");

}


/*F1 E21--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main21 (){
    float x, y;
    printf("Insira o valor de x:\n");
    scanf("%f",&x);

    if (x<=(-4))
        y = pow((x-1),2)-2*x+3;
    else
        if (-4<x && x<=3)
            y = (x/2)-5;
        else
            y = sqrt(x-2)*5;
    printf("y = %f",y);

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



/*F1 E23--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main23 (){
    int n;
    n=0;

    printf("Introduza o numero de 0 a 12:\n");
    scanf ("%d",&n);

    if (n==1) printf("Janeiro");
    if (n==2) printf("Fevereiro");
    if (n==3) printf ("Marco");
    if (n==4) printf("Abril");
    if (n==5) printf("Maio");
    if (n==6) printf("Junho");
    if (n==7) printf("Julho");
    if (n==8) printf("Agosto");
    if (n==9) printf ("Setembro");
    if (n==10) printf("Outubro");
    if (n==11) printf("Novembro");
    if (n==12) printf("Dezembro");
}



/*F1 E24--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main24 (){
    int n, N;
    float r, x, y, xC, yC;
    N=0;

    printf ("Insira o raio da circunferencia:\n");
    scanf ("%f",&r);
    printf ("Insira o centro da cincurfernecia:\n");
    scanf ("%f %f", &xC, &yC);
    printf("Insira o numero de pontos:\n");
    scanf ("%d", &n);


    while ( N<n )
        {
        printf("Insira um ponto:\n");
        scanf ("%f %f", &x, &y);

        if ( sqrt( pow(x-xC,2) + pow(y-yC,2) ==r ))
            { printf ("O ponto esta na cicunferencia.\n\n");}

        if ( sqrt( pow(x-xC,2) + pow(y-yC,2) >r ))
                { printf("O ponto esta fora da cirfunferencia.\n\n"); }

        if (sqrt( pow(x-xC,2) + pow(y-yC,2) <r ))
            { printf("O ponto esta dentro da cirfunferencia.\n\n");}

            N++;
        }
}



/*F1 E25--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main25 (){


float n, total, resultado, x;

n=0;
total=0;

    while (x>=0)
        {
    total= total+x;
    n=n+1;

    printf("Introduza x:\n");
    scanf("%f", &x);
        }

resultado= total/n;
printf(" resultado: %f", resultado);

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




/*F1 E27--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
 void main27 (){
    int n , ni, np;

    ni=0;
    np=0;

    while (n>=0)
    {
        if (n%2==0)
            np=np+1;
        else
            ni=ni+1;

        printf("Insira um numero inteiro:\n");
        scanf("%d", &n);
    }
    printf("Numeros pares:%d\n Numeros impares:%d\n", np, ni);
}



/*F1 E28--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main28 (){
    int idade, maior, menor;
    float media, n;

    idade=0;
    maior=0;
    menor=999;
    media=0;

    printf("Insira as idades:\n");
    scanf("%d", &idade);

    while (idade>0)
    {
        if (idade>maior)
        {maior=idade;}

        if (idade<menor)
        {menor=idade;}

        scanf("%d", &idade);
        n++;
    }
    media=media+idade;
    media=media/n;

    printf("Idade Maior:%d\n Idade Menor:%d\n Media das Idades:%f\n", maior, menor, media);
}



/*F1 E29--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main29 (){         //IMPORTANTE PARA 1*TESTE
    int n;
    float peso, media, pesada, soma;

    n=0;
    soma=0;
    media=0;
    media=0;
    peso=0;

    printf("Introduza os pesos:\n");
    scanf("%f", &peso);

    while (peso>0)
    {
        if (peso>0)
        {
            soma=soma+peso;
            n=n+1;
        }
        else
        {
            pesada=peso;
        }

        media=soma/n;
        printf("Media (pesos>60Kg) : %f\n Menor peso (pesos<60Kg):%f\n", media, pesada );
    }

}



/*F1 E30--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/
void main30 (){         //IMPORTANTE PARA 1*TESTE
    int ha, hb, tha, thb, i;


    i=1;
    tha=0;
    thb=0;
    ha=500;
    hb=1500;

    do
        {
            tha = ha*0.052;
            thb = hb*0.018;
            i++;

            ha=tha;
            hb=thb;

        }while (tha<thb);

        printf(" Sao necessarios %d anos.", i);

}



/*F1 E31--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
n (inteiro) -> Numero a verificar

RESULTADOS PRETENDIDOS:
i (inteiro) -> divisor

CONHECIMENTO REQUERIDO:
i é divisor de n se e só se n%i == 0

ESTRATÉGIA:
Obter o numero n a verificar.
Repetir este processo até que i seja maior que n+1:
Verificar a condição n%i==0. Se verdadeira, i é divisor.

--PSEUDOCODIGO--
*/
int main31(){
   int n,i;
   SetConsoleOutputCP(1252);
   printf("Insira um valor para verificar os seus divisores: \n");
   scanf("%d", &n);
   for (i = 1; i < n+1; i++)
   {
       if (n%i==0)
       {
           printf("Divisor: %d \n", i);
       }
   }
   return 0;
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
int main32(){
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



/*F1 E33--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
n (inteiro) -> Numero a verificar

RESULTADOS PRETENDIDOS:
Se n é um numero perfeito ou não.

CONHECIMENTO REQUERIDO:
i é divisor de n se e só se n%i == 0
Se a soma dos divisores i - o numero a verificar for igual a esse
proprio numero, então n é um numero perfeito.

ESTRATÉGIA:
Obter o numero n a verificar.
Repetir este processo até que i seja maior que n+1:
Verificar a condição n%i==0. Se verdadeira, i é divisor e soma-se a soma.
Terminado este processo, se a soma-n for igual a n,
o numero n é um numero perfeito.


--PSEUDOCODIGO--
INICIO("perfeito")
    soma<-0
    MOSTRA("Insira o valor a verificar")
    OBTEM(n)
    PARA(i=1; i<n+1; i++) FAZER
        SE(n%i==0) FAZER
            MOSTRAR("n")
            soma<-soma+i;
            MOSTRA("soma")
        FIM SE
    FIM PARA
    SE(soma-n==n)
        MOSTRA("n é perfeito")
    ELSE
        MOSTRA("n não é perfeito")
    FIM SE
FIM("perfeito")



*/
int main(){
   int n,i,soma=0;
   SetConsoleOutputCP(1252);

   printf("----------Verificação de Números Perfeitos----------");
   printf("Insira um valor para verificar se é perfeito: \n");
   scanf("%d", &n);

   for (i = 1; i < n+1; i++)
   {
       if (n%i==0)
       {
           printf("\ndivisor: %d", i);
           soma=soma+i;
           printf("\nsomando... : %d", soma);
       }
   }
   if(soma-n==n)
    printf("\n\n%d é um número perfeito", n);
   else
    printf("\n\n%d é não um número perfeito", n);


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
void main35 (){ //SOMATÓRIO, NAO PERCEBI, NÃO SEI RESOLVER SOMATORIOS

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



/*F1 E36--------------------------------------------------------------------

--MAPA DE ANALISE DE PROBLEMA--

DADOS DE ENTRADA:
RESULTADOS PRETENDIDOS:
CONHECIMENTO REQUERIDO:
ESTRATÉGIA:


--PSEUDOCODIGO--
*/








