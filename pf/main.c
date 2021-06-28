#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	ft_printf("%-15.p", (void *)0);
	printf("\n%-15.p", (void *)0);
}
