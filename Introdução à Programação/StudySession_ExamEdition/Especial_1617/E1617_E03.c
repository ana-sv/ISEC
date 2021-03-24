//Especial 2016/2017
//Ex 3


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

int main(){
    char origem[TAM], token[TAM];
    int i, j, cont=0;

    printf("\nInsira a frase incial:\n");
    gets(origem);
    printf("\nInsira o token a pesquisar:\n");
    gets(token);

    for(i=0; token[i]!='\0' ; i++){

        for(j=0; origem[j]!='\0'; j++){

            if(token[i]==origem[j])
                cont++;
        }
    }

    printf("\n\nForam encontrados %d caracteres do token %s.", cont, token);

}
