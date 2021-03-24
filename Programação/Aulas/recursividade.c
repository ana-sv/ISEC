
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f1(int x){

    printf("%d\n", x++);
    f1(x);   
}

int f(int n){
    int k;
    
    printf("Entrou com %d\n", n);
    if(n <= 1){
        printf("Vai sair com %d\n", 1);
        return 1;
    }
    else{
        printf("Pedir ajuda para %d\n", n-1);
        k = f(n-1);
        printf("Regressou para %d com %d\n", n-1, k);
        printf("Vai sair para %d com %d\n", n, k*n);
        return n * k;
    }
}


int conta(char *p){   
    if(*p == '\0')
        return 0;
    else
        return 1 + conta(p+1);
}

void m(char *p){
    if(*p == '\0')
        return;
    else{
        m(p+1);
        putchar(*p);   
    }
}

int capicua(char *p, int tam){

    if(tam<=1)
        return 1;
    else if(p[0] != p[tam-1])
        return 0;
    else
        return capicua(p+1, tam-2);
}



int main(){    

    //int x = 4;
    //printf("Fatorial de %d e %d\n", x, f(x));
    
    char st[50] = "ABCDDCBA";
    int v;
    
    //v = conta(st);  
    //printf("A string %s tem %d caracteres\n", st, v);
    
    //m(st);
    
    v = capicua(st, strlen(st));
    printf("%d\n", v);
   
    return 0;  
}

