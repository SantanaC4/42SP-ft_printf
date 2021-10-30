#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int a;
	int b;


	a = ft_printf("asdi%cfasdfa%c%c%c \n",'a','c','b','g');
	printf("%d\n", a);
	b = printf("asdi%cfasdfa%c%c%c \n",'a','c','b','g');
	printf("%d\n", b);

	return 0;
}
