#include <stdio.h>
#include <string.h>

int main(){

    char msg[4][20] = {"Out of range", "Printer off-line", "Paper out", "Irrecoverable error"};
    
    char *p_msg[4] = {"Out of range", "Printer off-line", "Paper out", "Irrecoverable error"}; 
    
    int i;
    
    for(i=0; i<4; i++)
        if(msg[i][0] == 'P')
            puts(msg[i]);
    
    printf("\n\n");
    
    for(i=0; i<4; i++)
        if(p_msg[i][0] == 'P')
            puts(p_msg[i]);
    
    return 0;
}