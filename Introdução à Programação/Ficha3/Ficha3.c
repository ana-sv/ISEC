////////////////////////////////////////////////////////////////////////////
/////////// Introdução à Programação - Ficha Laboratorial 3 ////////////////

/*F3 E00--------------------------------------------------------------------

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

/*--F3 E04----------------------------------------------------------------


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



int main4() {
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
