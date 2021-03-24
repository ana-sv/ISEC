//Exame Normal 29 de Janeiro 2016
//Ex 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMFRASE 50
#define TAMFIM 75

int func(char st1[], char st2[], char stfim[], int tamf){
    int i, j, tamf1, tamf2;

    tamf1=strlen(st1);
    tamf2=strlen(st2);

    if(tamf>=tamf1+tamf2){

        if(tamf1>tamf2){

            for(i=0,j=0;st2[j]!='\0';j++){
                stfim[i]=st1[j];
                stfim[i+1]=st2[j];

                if(j==tamf2) i++;
                else i+=2;
            }

            for(;st1[j]!='\0';j++,i++)
                stfim[i]=st1[j];
                stfim[i]='\0';
        }

        else if(tamf2>tamf1){
            for(i=0,j=0;st1[j]!='\0';j++,i+=2){
                stfim[i]=st1[j];
                stfim[i+1]=st2[j];
            }

            for(;st2[j]!='\0';j++,i++)
                stfim[i]=st2[j];
                stfim[i]='\0';
            }

        else{
            for(i=0,j=0;st2[j]!='\0';j++,i+=2){
                stfim[i]=st1[j];
                stfim[i+1]=st2[j];
            }
            stfim[i]='\0';
            }

    return 1;

    }
return 0;

}


void main(){
    char f1[TAMFRASE], f2[TAMFRASE], final[TAMFIM];

    printf("Indique a frase 1: "); gets(f1);
    printf("Indique a frase 2: "); gets(f2);

    if(func(f1, f2, final, TAMFIM))
        printf("Frase modificada:\n%s\n",final);
    else
        printf("Frase não modificada!\n");
}
