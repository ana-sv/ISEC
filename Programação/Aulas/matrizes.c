#include <stdio.h>

void escreveMatriz(int nLin, int nCol, int a[][nCol]){
    int i, j;

    for(i=0; i<nLin; i++){
        for(j=0; j<nCol; j++)
            printf("%d\t", a[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

int main(){    
    int mat[2][3] = {{1,2,3},{4,5,6}};
    int *p;
    
    escreveMatriz(2, 3, mat);
    
    p = mat[1];
    p--;
    printf("%d\n", *p);
    
   return 0;
}



