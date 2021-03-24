
#include <stdio.h>
#include <string.h>

int comuns(int *a, int tamA, int *b, int tamB){

    int i, j,total = 0;

    for(i=0; i< tamA; i++)      // Percorrer o primeiro array
        for(j=0; j<tamB; j++)
            if(a[i] == b[j]){
                printf("%d\n", a[i]);
                total++;
            }
    return total;
}

int comunsM(int *a, int tamA, int *b, int tamB){
     int i=0, j=0,total = 0;

     while(i<tamA && j<tamB){
         if(a[i] < b[j])
             i++;
         else if(a[i] > b[j])
             j++;
         else{
             printf("%d\n", a[i]);
             total++;
             i++;
             j++;
         }
     }
     printf("Array A: %d\n", i);
     printf("Array B: %d\n", j);
     return total;
}

int mainTab(){
    int a[] = {5,6,7,8, 9,11,12,14};
    int b[] = {5,6,7,8, 9,11,12,14};

    printf("Elementos em comum: %d\n", comunsM(a, 8, b, 8));
    return 0;
}



int main(int argc, char* argv[]){
    int i;

    if(argc != 3)
        printf("Erro de utilizacao\n");
    else if(strlen(argv[1]) != strlen(argv[2]))
        printf("Tamanhos diferentes\n");
    else{
        for(i=0; i<strlen(argv[1]); i++){
            putchar(argv[1][i]);
            putchar(argv[2][i]);
        }

        printf("\n\n");
    }

    return 0;
}
