//Exame Normal 2016/2017
//Ex (2.a) e (2.b)

#include <stdio.h>

/*----ANALISE DA FUNCAO----

Dados de Entrada:
    base(real)- nota base
    dificuldade(inteiro)- nivel de dificuldade
    faltas(inteiro)- faltas de cada concocrrente

Resultados Pretendidos:
    nota(real)- nota final do concorrente

Processamento Requerido:
    Recebe base, dificuldade e faltas.
    Calcular a nota através das seguintes operações:
        nota=(base*dificuldade)-faltas
        se nota>faltas então nota=2*nota;
    Devolve nota;

----PSEUDOCODIGO----
INICIO FUNCAO "notaFinal"
    Recebe(nota, dificuldade, faltas)
    nota<-0
    nota<-(base*dificuldade)-faltas
    SE (nota>faltas) FAZER
        nota<-2*nota
    FIM SE
    DEVOLVE nota
FIM FUNCAO "notaFinal"

*/


float notaFinal (float base, int dificuldade, int faltas){
    float nota=0;
    nota=(base*dificuldade)-faltas;
    if(base>faltas)
        nota=2*nota;
    return nota;
}

int main(){
    int equipa, jogador, d, f, equipaVencedora;
    float b, notaConc, notaBaixa=999999, notaEquipa=0, notaVencedora=0;

    printf("\n----Concurso de Habiliades----\n");
    for(equipa=1 ; equipa<=2; equipa++){
        printf("\n\nEquipa %d", equipa);

        notaEquipa=0;

        //Calcular notas dos jogadores
        for(jogador=1; jogador<=3; jogador++){
            printf("\nNota base, nivel de dificuldade e numero de faltas?");
            scanf("%f %d %d",&b ,&d ,&f);
            notaConc=notaFinal(b,d,f);
            printf("Nota do concorrente: %0.1f\n", notaConc);
            notaEquipa+=notaConc; // notaEquipa=notaEquipa+notaConc;


            //Identificar a menor nota da equipa
            if(notaConc<notaBaixa)
                notaBaixa=notaConc;


        }
        notaEquipa=notaEquipa-notaBaixa;
        printf("\nNota da equipa: %0.1f", notaEquipa);

        if(notaEquipa>notaVencedora){
            notaVencedora=notaEquipa;
            equipaVencedora=equipa;
        }
    }
    printf("\n\nA equipa vencedora foi a %d\n\n", equipaVencedora);
}
