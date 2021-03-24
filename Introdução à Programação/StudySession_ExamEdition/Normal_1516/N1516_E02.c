//Exame Normal 29 de Janeiro 2016
//Ex 2.a) 2.b

#include <stdio.h>

float media_final(int valor, int valido){
    static int soma=0, cont=0;

    if(valido==1){
        soma=soma+valor;
        cont++;
        return 0;
    }
    return (float)soma/cont;
}

int main(){

    int n, i, valor=0;

    printf("\n\nInsira o numero de valores (0 a 10) : ");
    scanf("%d", &n);

    if(n<0 || n>10)
        printf("\nValor introduzido inválido!");

    for(i=0; i<n; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);

        media_final(valor,1);
    }
    printf("\n\nA media dos %d numeros e': %0.2f\n\n", n, media_final(0,0));
}
