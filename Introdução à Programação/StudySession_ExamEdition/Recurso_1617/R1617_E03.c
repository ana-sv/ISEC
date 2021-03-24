//Recurso 2016/2017
//Ex 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 250

int main(){
    char frase[250], c_aux, c_max;
    int i, j , cont=1, max=0;

    printf("Insira a frase pretendida: ");
    gets(frase);

    for(i=0; frase[i]; i++){ //percorre a frase

        c_aux=frase[i];

        for(j=0; frase[j]; j++) //conta as x que aparece o caracter
            if(c_aux==frase[j]) cont++;

        if(cont > max ){
            max = cont;
            c_max = c_aux;

        }
        cont=0; //reset da contagem para que possa ser utilizada no proximo caracter

    }
    printf("Caracter mais frequente: %c", c_max);

}
