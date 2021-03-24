#include <stdio.h>
#include <stdlib.h>


/*Desafio 1 - 28 Fevereiro 2018
 * 
 * Um vetor de inteiros armazena o peso em gramas de um conjunto de bolos de 
 * uma pastelaria. Cada posição armazena o peso de um dos bolos disponíveis. 
 * Escreva uma função com protótipo:

int verificaBolos(int v[], int tam, int pesototal); 

 * que verifique se existem 3 bolos na pastelaria cujo peso total seja 
 * exatamente igual a um valor indicado. A função recebe como parâmetros o 
 * vetor de inteiros, o número de bolos disponíveis e o valor do peso total 
 * a verificar. Pode assumir que o vetor tem, pelo menos, 3 elementos e que 
 * não existem 2 bolos com o mesmo peso.

 * A função deve escrever na consola os vários conjuntos de 3 bolos que permitem 
 * atingir o peso pretendido (um conjunto por linha). Devolve, além disso, o 
 * número de conjuntos que satisfaz a condição. 

Exemplo:
Parâmetros de entrada na função: {1, 2, 3, 4, 5, 6}, 6, 8

Output na consola: 

1  2  5 
1  3  4

Devolve 2
*/
/*
int verificaBolos(int v[], int tam, int pesototal){
    int a, b, c, cont=0;

    
    
    // 1. bolo
    for(a=0; a<tam; a++){
        //2. bolo
        for(b=a+1; b<tam; b++){
            //3. bolo
            for(c=b+1; c<tam; c++){
                if (v[a]+v[b]+v[c]==pesototal){
                    cont++;
                    printf("%d %d %d\n", v[a], v[b], v[c]);
                }
            }
            
        }
    }
    return cont;
}

int main() {
    int a[] = {1,2,3,4,5,6};
    printf("%d\n", verificaBolos(a, 6, 8)); 

   }
*/




/*Desafio 2 - 8 Março 2018
 
 Escreva uma função que verifique quantos elementos em comum existem em 
 2 vetores de inteiros. Os vetores podem ter tamanhos diferentes, 
 elementos repetidos e não estão ordenados. 
 
 A função tem o seguinte protótipo:
int comuns(const int *vA, int tamA, const int *vB, int tamB); 

Recebe ponteiro para o início e dimensão de cada um dos 
vetores e devolve o número de valores em comum.

Exemplo:
Se a função receber como parâmetros:
 {1, 3, 2, 6, 5, 4}, 6, {9, 5, 3, 3, 1, 4, 8, 7, 23}, 9
Deve devolver 4
 * 
 */
/*
int comuns(const int *vA, int tamA, const int *vB, int tamB){
    int i, j, k, cont=0;
    
    //Remove elementos duplicados de vB
    for (i=0; i<tamB; i++) {
      for (j=i+1; j<tamB; j++) {
          if(vB[i]==vB[j])
              cont=cont-1;
      }
    }
    //Remove elementos duplicados de vA
    for (i=0; i<tamA; i++) {
      for (j=i+1; j<tamA; j++) {
          if(vA[i]==vA[j])
              cont=cont-1;
      }
    }
    
    //Encontrar elementos comuns
    for(i=0; i<tamA; i++){
        
       for(j=0; j<tamB; j++){
           
         if(vA[i]==vB[j])
            cont++;
        }
    }
        
    return cont;
}

int main()
   {
    const int a[6] = {1, 3, 2, 6, 5, 4};
    const int b[9] = {9, 5, 3, 3, 1, 4, 8, 7, 23};
    printf("%d\n", comuns(a, 6, b, 9)); 
   }
 */