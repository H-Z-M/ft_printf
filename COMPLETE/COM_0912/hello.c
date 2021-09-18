#include "ft_printf.h"
#include <float.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stddef.h>

int ft_printf(const char* format, ...);
int main()
{
	ft_printf("|%'d|\n", 127123);
	printf("|%'d|\n", 127123);
	ft_printf("|%#x|\n", 0);
	printf("|%#x|\n", 0);
	return 0;
	ptrdiff_t d = 1211111111112345678;
	ft_printf("%td\n", d);
	printf("%td\n", d);
	/* ft_printf("%3.20e\n", 2.147483648); */
	/* printf("%3.20e\n", 2.147483648); */
	/* ft_printf("%3.20e\n", 2.147483647); */
	/* printf("%3.20e\n", 2.147483647); */
	ft_printf("%lld\n", LLONG_MAX);
	printf("%lld\n", LLONG_MAX);

	char *s = "%zu\n";
	ft_printf(s, sizeof(ptrdiff_t));
	printf(s, sizeof(ptrdiff_t));
	ft_printf(s, (size_t)-1);
	printf(s, (size_t)-1);
	ft_printf(s, (unsigned int)-1);
	printf(s, (unsigned int)-1);
	/* ft_printf("%.*d\n", INT_MIN, 5); */
	/* printf("%.*d\n", INT_MIN, 5); */
}
