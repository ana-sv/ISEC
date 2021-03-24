//Recurso 2016/2017
//Ex (2.a) e (2.b)

/*----Analise da Funçao----

Dados de Entrada:
    custoBase(real)-> custo base da refeicao
    tipoUtente(inteiro)-> tipo de utente que compra a refeiçao
    nSobremesas(inteiro)-> numero de sobremesas compradas
    nCafes(inteiro)-> numero de sobremesas compradas

Resultados Pretendidos:
    refeicao(real)-> custo da refeiçao pretendida

Processamento Requerido:


----Pseudocodigo----
INICIO FUNCAO "custoRef"

FIM FUNÇÃO "custoRef"
*/

//NOTA: o programa está a contar ainda a refeicao que tem como tipoUtente 5.
//Isto faz com que o limMin seja sempre zero, o que não é correcto.

#include <stdio.h>


float custoRef(float custoBase, int tipoUtente, int nSobremesas, int nCafes);

int main (){
    float custoBase, soma, refeicao=0, lim1=0, lim2=0, limMin=999999, limMax=0;
    int tipoUtente, nSobremesas, nCafes, contRef=0, a=0, b=0, c=0;

    printf("\n-----Cantina Manager-----\n");
    printf("\nQual o valor da refeicao base? ");
    scanf("%f", &custoBase);

    do{
        printf("\nQual o tipo de utente? Numero de sobremesas extra? Numero de cafes? ");
        scanf("%d %d %d", &tipoUtente, &nSobremesas, &nCafes);
        refeicao = custoRef(custoBase, tipoUtente, nSobremesas, nCafes);

        soma += refeicao;

        //Saber limite Min e Max
        if(refeicao<limMin)
            limMin=refeicao;
        if(refeicao>limMax)
            limMax=refeicao;

        lim1=limMin+(limMax-limMin)/3;
        lim2=limMin+2*(limMax-limMin)/3;

        if(refeicao>=limMin && refeicao<lim1)
            a++;
        if(refeicao>=lim1 && refeicao<lim2)
            b++;
        if(refeicao>=lim2 && refeicao<=limMax)
            c++;

        contRef++;
    }while( tipoUtente != 5 );

    printf("Foram consumidas %d refeicoes totalizando: %0.2f \n", contRef-1 , soma);
    printf("Distribuidas da seguinte forma:\n");


    printf("\n>= %0.2f e < %0.2f -> %d ref",limMin, lim1, a );
    printf("\n>= %0.2f e < %0.2f -> %d ref",lim1, lim2, b );
    printf("\n>= %0.2f e <= %0.2f -> %d ref",lim2, limMax, c );
}


float custoRef(float custoBase, int tipoUtente, int nSobremesas, int nCafes){
    float refeicao=0;

    if (tipoUtente==1)
        refeicao = custoBase - (custoBase*0.4);
    else if  (tipoUtente==2)
        refeicao=custoBase;
    else
        return 0;

    if(nSobremesas==1)
        refeicao += 0.60;
    else if (nSobremesas>1)
            refeicao += nSobremesas;
    refeicao += (nCafes*0.40);

    printf("Custo da refeicao: %0.2f\n", refeicao);

    return refeicao;
}
