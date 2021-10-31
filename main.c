#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a;
	int b;
	char *x = "sdfs";

	a = ft_printf("%p\n", (void*)0);
	printf("%d\n", a);
	b = printf("%p\n", (void*)0);
	printf("%d\n", b);

	return 0;
}
