#include <stdio.h>
#include "./drivers/teste.h"

extern int teste10(void);

/**
 * hello.c
 */
int main(void)
{
    int teste = teste10();
	printf("Hello World!\n");
	
	printf("%i", teste);

	return 0;
}
