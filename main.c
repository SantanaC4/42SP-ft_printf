#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a;
	int b;
	char *x = "sdfs";

	a = ft_printf("%-1c\n", '0');
	printf("%d\n", a);
	b = printf("%-1c\n", '0');
	printf("%d\n", b);
	//TEST(1, print("%-1c", '0'));
	//TEST(2, print(" %-2c ", '0'));
	//TEST(3, print(" %-3c", '0' - 256));
	//TEST(4, print("%-4c ", '0' + 256));
	//TEST(5, print(" %-1c %-2c %-3c ", '0', 0, '1'));
	//TEST(6, print(" %-1c %-2c %-3c ", ' ', ' ', ' '));
	//TEST(7, print(" %-1c %-2c %-3c ", '1', '2', '3'));
	//TEST(8, print(" %-1c %-2c %-3c ", '2', '1', 0));
	//TEST(9, print(" %-1c %-2c %-3c ", 0, '1', '2'));

	return 0;
}
