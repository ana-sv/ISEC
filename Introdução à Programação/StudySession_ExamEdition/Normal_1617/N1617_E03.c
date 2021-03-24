//Exame Normal 2016/2017
//Ex 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dias_do_ano(int data[], int dias_dos_meses[]);
int ano_bissexto(int);

void main(){

    int normal, recurso;
    int dias_mes[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int data_normal[3]={17, 2, 2016}, data_recurso[3]={3, 3, 2016};

    if (normal = dias_do_ano(data_normal, dias_mes))
        if (recurso = dias_do_ano(data_recurso, dias_mes))
            printf("Numero de dias entre o exame Normal e o de Recurso = %3d\n", recurso-normal);
        else printf("A data do exame de Recurso nao e' valida\n");
    else printf("A data do exame Normal nao e' valida\n");


}



int dias_do_ano(int data[], int dias_dos_meses[]){
    int i, dias=0;

    if(ano_bissexto(data[2]) ==-1 )
        printf("\nData Invalida\n"); // a data nao e valida, fora do intervalo pretendido

    if(ano_bissexto(data[2]) == 1)//se o ano for bissexto
        dias_dos_meses[1]=29; //fevereiro que esta na 2 posicao tem 29dias
    else
        dias_dos_meses[1]=28;

    //contagem dos dias ate ao mes anterior ao presente
    for(i=0; i<data[1]-1; i++ )
        dias=dias+dias_dos_meses[i];

    //dias do mes presente
    dias=dias+data[0];

    return dias;


}


int ano_bissexto(int ano){

    int i;

    if(ano < 1583 || ano > 3851 )
        return -1; //não está no intervalo indicado no intervalo

    //como 2016 foi ano bissexto, a partir de esse ano e de 4 em 4
    // ha outro ano bissexto
    for(i=2016; i <= 3851 ; i+=4){
        if(i == ano)
            return 1; //então i é ano bisexto
    }

    //como 2016 foi ano bissexto, desse ano para tras de 4 em 4
    // ha outro ano bissexto
    for(i=2016; i >= 1583 ; i-=4){
        if(i == ano)
            return 1; //então i é ano bisexto
    }

    return 0;
}

