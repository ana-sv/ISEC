#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int x, y;
	
	if(argc != 4)
	{
		printf("Utilizacao incorrecta \n");
	}
	else
	{
		x = atoi(argv[1]);
		y = atoi(argv[3]);
		switch(*argv[2]){
			case '+': printf("Total: %d\n", x+y); break;
			case '-': printf("Total: %d\n", x-y); break;
			case '*': printf("Total: %d\n", x*y); break;
			case '/': if(y!=0) 
				printf("Total = %d\n", x/y);
				break;
			default: printf("Operacao invalida\n");
		}
	}
	return 0;
}
