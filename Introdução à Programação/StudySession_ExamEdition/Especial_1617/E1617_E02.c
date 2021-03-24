//Especial 2016/2017
//Ex (2.a) e (2.b)
// ESTA' MALLLL


#include <stdio.h>
#define TAM 50

/*----Pseudocodigo----
*/

int InsereNum( int num, int v[], int tam){
    int i=0, j, z;


    while(i<tam || v[i]!=-1)
        i++;

    if(i==tam)
        return 0;
    else
        return 1;

    for(j=0 ; j<tam; j++){
        if(num>v[j])
            v[tam-j]=v[j];
            v[j]=num;
    }

    for(z=0; z<tam ; z++)
        printf("%d", v);

}


int main(){
    int v[50]={-1}, i;

    printf("\n\n");
    for(i=0; i<TAM; i++){
        printf("\nInsira um numero inteiro positivo:");
        scanf("%d", &v[i]);
    }


    scanf("%d");
}
