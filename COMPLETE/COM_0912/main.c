#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/fcntl.h>


int ft_printf(const char* format, ...);
void test_printf_tester(void);


void errormsg()
{
	/* printf("\\\\\\\\\\\\\\\\error////////////////"); */
	/* exit(EXIT_FAILURE); */
}

/* extern long write(int, const char *, unsigned long); */
void myputchar(char c) {
  (void) write(1, 0, 1);
}

int		main(void)
{
	char ccc = 0;
	/* write(1,ccc,2); */
	/* printf("p |%-5c\n", '\0'); */
	/* ft_printf("f |%-5c\n", '\0'); */
	/* printf("p |%c\n", '\0'); */
	/* ft_printf("f |%c\n", '\0'); */
	/* printf("p |%c\n", NULL); */
	/* ft_printf("f |%c\n", NULL); */
	/* printf("p |%c\n", ccc); */
	/* ft_printf("f |%c\n", 0); */
	/* ft_printf("f |%c\n", 'A'); */
	/* write(1,NULL,1); */
	ft_printf("%c\n", 0);
	ft_printf("%c", 0);
	/* myputchar(0); */
	return 0;

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
	printf(" --- Return : %d\n", printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
	printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
	printf(" --- Return : %d\n", printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
	printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
	printf(" --- Return : %d\n", printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
	printf("\n");
	int O = 2;
	ft_printf("%0.*d\n",-1, O);
	printf("%0.*d\n",-1, O);
	ft_printf("%0*.*d, %.*d\n",11, -1, O, 3, O);
	printf("%0*.*d, %.*d\n",11, -1, O, 3, O);
	ft_printf("%-3d\n", O);
	printf("%-3d\n", O);
	// printf(" --- Return : %d\n", ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	// printf(" --- Return : %d\n", printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	/* printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j)); //T2 */
	/* printf(" --- Return : %d\n", printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j)); //T2 */
	/* printf(" --- Return : %d\n", ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d)); //T12 */
	/* printf(" --- Return : %d\n", printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d)); //T12 */
	/* printf(" --- Return : %d\n", ft_printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d\n", i, j, k, l, m, c, e, d)); //T12 */
	/* printf(" --- Return : %d\n", printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d\n", i, j, k, l, m, c, e, d)); //T12 */
	/* printf(" --- Return : %d\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d)); //T4 */
	/* printf(" --- Return : %d\n", printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d)); //T4 */
	/* printf(" --- Return : %d\n", ft_printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d)); //T5 */
	/* printf(" --- Return : %d\n", printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d)); //T5 */
	/* printf(" --- Return : %d\n", ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d)); //T6 */
	/* printf(" --- Return : %d\n", printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d)); //T6 */
	/* printf(" --- Return : %d\n", ft_printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d\n", i, j, k, l, m, c, e, d)); //T7 */
	/* printf(" --- Return : %d\n", printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d\n", i, j, k, l, m, c, e, d)); //T7 */
	/* printf(" --- Return : %d\n", ft_printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d\n", i, j, k, l, m, c, e, d)); //T8 */
	/* printf(" --- Return : %d\n", printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d\n", i, j, k, l, m, c, e, d)); //T8 */
	/* printf(" --- Return : %d\n", ft_printf("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d\n", i, j, k, l, m, c, e, d)); //T9 */
	/* printf(" --- Return : %d\n", printf("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d\n", i, j, k, l, m, c, e, d)); //T9 */
	/* printf(" --- Return : %d\n", ft_printf("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d\n", i, j, k, l, m, c, e, d)); //T10 */
	/* printf(" --- Return : %d\n", printf("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d\n", i, j, k, l, m, c, e, d)); //T10 */
	/* printf(" --- Return : %d\n", ft_printf("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d\n", i, j, k, l, m, c, e, d)); //T11 */
	/* printf(" --- Return : %d\n", printf("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d\n", i, j, k, l, m, c, e, d)); //T11 */
	a = -2;
	/* while (a < 5) //T34-69 */
	/* #<{(| while (a < 5) //T34-69 |)}># */
	/* { */
	/* 	printf(" --- Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d)); */
	/* 	printf(" --- Return : %d\n", printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d)); */
	/* 	printf(" --- Return : %d\n", ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d)); */
	/* 	printf(" --- Return : %d\n", printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d)); */
	/* 	printf(" --- Return : %d\n", ft_printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d)); */
	/* 	printf(" --- Return : %d\n", printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d)); */
	/* 	printf(" --- Return : %d\n", ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d)); */
	/* 	printf(" --- Return : %d\n", printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d)); */
	/* 	a++; */
	/* } */

	/* a = -4; */
	/* while (a < 2) //T187-213 */
	/* { */
	/* 	printf(" --- Return : %d\n", ft_printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u)); */
	/* 	printf(" --- Return : %d\n", printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u)); */
	/* 	printf(" --- Return : %d\n", ft_printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u)); */
	/* 	printf(" --- Return : %d\n", printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u)); */
    /*  */
	/* 	printf(" --- Return : %d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u)); */
	/* 	printf(" --- Return : %d\n", printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u)); */
	/* 	printf("\n"); */
	/* 	a++; */
	/* } */
	a = -1;
	while(a < 5) //T257-346
	{
		b = -1;
		while (b < 1)
		{
			/* printf(" --- Return : %d\n", ft_printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e)); */
			/* printf(" --- Return : %d\n", printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e)); */
			printf(" --- Return : %d\n", ft_printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			printf(" --- Return : %d\n", printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			printf(" --- Return : %d\n", ft_printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			printf(" --- Return : %d\n", printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			b++;
		}
		printf("\n");
		a++;
	}
	/* return 0; */
#ifndef foo

	int mi;
	int ii;
	char *ptr;
	char *np;;
	unsigned long long bs;

	bs = sizeof(unsigned long long) * 8;
	mi = (1 << (bs - 1)) + 1;
	ptr = "Hello world!";
	np = NULL;
	ii = 5;

	ft_printf("\n------------------------------------------------------------------------------------------------------");
	ft_printf("\nStrings:\n\n");
	if (ft_printf("Return Value: 13 / %d\n", ft_printf("%s\n", ptr)) !=
	printf("Return Value: 13 / %d\n", printf("%s\n", ptr)))
		errormsg();
	if (ft_printf("Return Value: 15 / %d\n", ft_printf("ft_printf test\n")) !=
	printf("Return Value: 15 / %d\n", printf("ft_printf test\n")))
		errormsg();

	/* Wide Characters */
	ft_printf("\n\n\nWide Characters:\n\n");
	if (ft_printf("Return Value: 51 / %d\n", ft_printf("ο Δικαιοπολις εν αγρω εστιν\n")) !=
	printf("Return Value: 51 / %d\n", printf("ο Δικαιοπολις εν αγρω εστιν\n")))
		errormsg();

	/* Octal, Decimal, Hex*/
	ft_printf("\n\n\nNumbers:\n\n");

	if (ft_printf("Return Value: 6 / %d\n",  ft_printf("%d = 5\n", ii)) !=
	printf("Return Value: 6 / %d\n",  printf("%d = 5\n", ii)))
		errormsg();
	if (ft_printf("Return Value: 24 / %d\n", ft_printf("%d = - max_int\n", mi)) !=
	printf("Return Value: 24 / %d\n", printf("%d = - max_int\n", mi)))
		errormsg();
	if (ft_printf("Return Value: 13 / %d\n", ft_printf("char %c = 'a'\n", 'a')) !=
	printf("Return Value: 13 / %d\n", printf("char %c = 'a'\n", 'a')))
		errormsg();
	if (ft_printf("Return Value: 12 / %d\n", ft_printf("hex %x = ff\n", 0xff)) !=
	printf("Return Value: 12 / %d\n", printf("hex %x = ff\n", 0xff)))
		errormsg();
	if (ft_printf("Return Value: 12 / %d\n", ft_printf("hex %X = FF\n", 0xff)) !=
	printf("Return Value: 12 / %d\n", printf("hex %X = FF\n", 0xff)))
		errormsg();
	if (ft_printf("Return Value: 12 / %d\n", ft_printf("hex %02x = 00\n", 0)) !=
	printf("Return Value: 12 / %d\n", printf("hex %02x = 00\n", 0)))
		errormsg();
	if (ft_printf("Return Value: 47 / %d\n", ft_printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3)) !=
	printf("Return Value: 47 / %d\n", printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3)))
		errormsg();

	/* Special things*/
	ft_printf("\n\n\nSpecial things...(?):\n\n");
	if (ft_printf("Return Value: 14 / %d\n", ft_printf("%d %s(s)%%\n", 0, "message")) !=
	printf("Return Value: 14 / %d\n", printf("%d %s(s)%%\n", 0, "message")))
		errormsg();
	if (ft_printf("Return Value: 31 / %d\n", ft_printf("newline with n at the end: $\nn\n")) !=
	printf("Return Value: 31 / %d\n", printf("newline with n at the end: $\nn\n")))
		errormsg();
	if (ft_printf("Return Value: 20 / %d\n", ft_printf("%d %s(s) with %%\n", 0, "message")) !=
	printf("Return Value: 20 / %d\n", printf("%d %s(s) with %%\n", 0, "message")))
		errormsg();
	if (ft_printf("Return Value: 26 / %d\n", ft_printf("pointer ptr = %p\n", ptr)) !=
	printf("Return Value: 26 / %d\n", printf("pointer ptr = %p\n", ptr)))
		errormsg();

	/* (void)np; */
	if (ft_printf("Return Value: 20 / %d\n", ft_printf("%p is null pointer\n", np)) !=
	printf("Return Value: 20 / %d\n", printf("%p is null pointer\n", np)))
		errormsg();
	if (ft_printf("Return Value: 20 / %d\n", ft_printf("%c is null character\n", '\0')) !=
	printf("Return Value: 20 / %d\n", printf("%c is null character\n", '\0')))
		errormsg();
	/* return 0; */
#endif
	char buf[30];
	/* Text Justification */
	ft_printf("\n\n\nJustify text:\n\n");
	sprintf(buf, "justif: \"%-10s\"\n", "left");
	if (ft_printf("Return Value: 21 / %d\n", ft_printf("%s", buf)) !=
	printf("Return Value: 21 / %d\n", printf("%s", buf)))
		errormsg();
	sprintf(buf, "justif: \"%10s\"\n", "right");
	if (ft_printf("Return Value: 21 / %d\n", ft_printf("%s", buf)) !=
	printf("Return Value: 21 / %d\n", printf("%s", buf)))
		errormsg();
	sprintf(buf, " 3: %04d zero padded\n", 3);
	if (ft_printf("Return Value: 21 / %d\n", ft_printf("%s", buf)) !=
	printf("Return Value: 21 / %d\n", printf("%s", buf)))
		errormsg();
	sprintf(buf, " 3: %-4d left justif.\n", 3);
	if (ft_printf("Return Value: 22 / %d\n", ft_printf("%s", buf)) !=
	printf("Return Value: 22 / %d\n", printf("%s", buf)))
		errormsg();
	sprintf(buf, " 3: %4d right justif.\n", 3);
	if (ft_printf("Return Value: 23 / %d\n", ft_printf("%s", buf)) !=
	printf("Return Value: 23 / %d\n", printf("%s", buf)))
		errormsg();
	sprintf(buf, "-3: %04d zero padded\n", -3);
	if (ft_printf("Return Value: 21 / %d\n", ft_printf("%s", buf)) !=
	printf("Return Value: 21 / %d\n", printf("%s", buf)))
		errormsg();
	sprintf(buf, "-3: %-4d left justif.\n", -3);
	if (ft_printf("Return Value: 22 / %d\n", ft_printf("%s", buf)) !=
	printf("Return Value: 22 / %d\n", printf("%s", buf)))
		errormsg();
	sprintf(buf, "-3: %4d right justif.\n", -3);
	if (ft_printf("Return Value: 23 / %d\n", ft_printf("%s", buf)) !=
	printf("Return Value: 23 / %d\n", printf("%s", buf)))
		errormsg();

	/* Emojis */
	ft_printf("\n\n\nEmojis:\n\n");
	if (ft_printf("Return Value: 519 / %d\n", ft_printf("😀 😃 😄 😁 😆 😅 😂 😊 😇 😉 😌 😍 😘 😗 😙 😚 😋 😜 😝 😛 😎 😏 😒 😞 "
	"😔 😟 😕 🙁 😣 😖 😫 😩 😤 😠 😡 😶 😐 😑 😯 😦 😧 😮 😲 😵 😳 😱 😨 😰 😢 😥 😭 "
	"😓hahaha 😪 😴 🙄 🤔 😬 😷 😈 👿 👹 👺 💩 👻 💀 👽 👾 🤖 🎃 😺 😸 😹 😻 😼 😽 🙀 😿 😾 "
	"👐 🙌 👏 🙏 👍 👎 👊 ✊ 👌 👈 👉 👆 👇 ✋ 👋 💪 💅 💄 💋 👄 👅 👂 👃 👣 👀 👤 \n")) !=
	printf("Return Value: 519 / %d\n", printf("😀 😃 😄 😁 😆 😅 😂 😊 😇 😉 😌 😍 😘 😗 😙 😚 😋 😜 😝 😛 😎 😏 😒 😞 "
	"😔 😟 😕 🙁 😣 😖 😫 😩 😤 😠 😡 😶 😐 😑 😯 😦 😧 😮 😲 😵 😳 😱 😨 😰 😢 😥 😭 "
	"😓hahaha 😪 😴 🙄 🤔 😬 😷 😈 👿 👹 👺 💩 👻 💀 👽 👾 🤖 🎃 😺 😸 😹 😻 😼 😽 🙀 😿 😾 "
	"👐 🙌 👏 🙏 👍 👎 👊 ✊ 👌 👈 👉 👆 👇 ✋ 👋 💪 💅 💄 💋 👄 👅 👂 👃 👣 👀 👤 \n")))
		errormsg();

	/* Long Ass String */
	ft_printf("\n\n\nCool story:\n\n");
	if (ft_printf("Return Value: 1561 / %d\n",
	ft_printf("What the fuck did you just fucking say about me, you little \n"
	"bitch? I’ll have you know I graduated top of my class in the Navy \n"
	"Seals, and I’ve been involved in numerous secret raids on Al-Quaeda, \n"
	"and I have over 300 confirmed kills. I am trained in gorilla warfare \n"
	"and I’m the top sniper in the entire US armed forces. You are nothing \n"
	"to me but just another target. I will wipe you the fuck out with \n"
	"precision the likes of which has never been seen before on this Earth, \n"
	"mark my fucking words. You think you can get away with saying that shit \n"
	"to me over the Internet? Think again, fucker. As we speak I am \n"
	"contacting my secret network of spies across the USA and your IP is \n"
	"being traced right now so you better prepare for the storm, maggot. \n"
	"The storm that wipes out the pathetic little thing you call your life. \n"
	"You’re fucking dead, kid. I can be anywhere, anytime, and I can kill \n"
	"you in over seven hundred ways, and that’s just with my bare hands. \n"
	"Not only am I extensively trained in unarmed combat, but I have access \n"
	"to the entire arsenal of the United States Marine Corps and I will use \n"
	"it to its full extent to wipe your miserable ass off the face of the \n"
	"continent, you little shit. If only you could have known what unholy \n"
	"retribution your little “clever” comment was about to bring down upon \n"
	"you, maybe you would have held your fucking tongue. But you couldn’t, \n"
	"you didn’t, and now you’re paying the price, you goddamn idiot. I will \n"
	"shit fury all over you and you will drown in it. You’re fucking dead, \n"
	"kiddo.\n")) !=
	printf("Return Value: 1561 / %d\n",
	printf("What the fuck did you just fucking say about me, you little \n"
	"bitch? I’ll have you know I graduated top of my class in the Navy \n"
	"Seals, and I’ve been involved in numerous secret raids on Al-Quaeda, \n"
	"and I have over 300 confirmed kills. I am trained in gorilla warfare \n"
	"and I’m the top sniper in the entire US armed forces. You are nothing \n"
	"to me but just another target. I will wipe you the fuck out with \n"
	"precision the likes of which has never been seen before on this Earth, \n"
	"mark my fucking words. You think you can get away with saying that shit \n"
	"to me over the Internet? Think again, fucker. As we speak I am \n"
	"contacting my secret network of spies across the USA and your IP is \n"
	"being traced right now so you better prepare for the storm, maggot. \n"
	"The storm that wipes out the pathetic little thing you call your life. \n"
	"You’re fucking dead, kid. I can be anywhere, anytime, and I can kill \n"
	"you in over seven hundred ways, and that’s just with my bare hands. \n"
	"Not only am I extensively trained in unarmed combat, but I have access \n"
	"to the entire arsenal of the United States Marine Corps and I will use \n"
	"it to its full extent to wipe your miserable ass off the face of the \n"
	"continent, you little shit. If only you could have known what unholy \n"
	"retribution your little “clever” comment was about to bring down upon \n"
	"you, maybe you would have held your fucking tongue. But you couldn’t, \n"
	"you didn’t, and now you’re paying the price, you goddamn idiot. I will \n"
	"shit fury all over you and you will drown in it. You’re fucking dead, \n"
	"kiddo.\n")))
		errormsg();

/* 	return (0); */
/* } */



/* int main() */
/* { */
	printf("-10 => [%#x]  ", -10);
	printf("10 => [%#x]  ", 10);
	printf("10 => [%x]  ", 10);
	printf("-1 => [%#x]  ", -1);
	printf("1 => [%#x]  ", 1);
	printf("1 => [%x]\n", 1);
	ft_printf("-10 => [%#x]  ", -10);
	ft_printf("10 => [%#x]  ", 10);
	ft_printf("10 => [%x]  ", 10);
	ft_printf("-1 => [%#x]  ", -1);
	ft_printf("1 => [%#x]  ", 1);
	ft_printf("1 => [%x]\n", 1);

	int Y = 100;
	if (ft_printf("%d%%salut%10d\n", 'h', (int)(uintptr_t)Y) !=
	printf("%d%%salut%10d\n", 'h', (int)(uintptr_t)Y))
		errormsg();

	if (ft_printf("good%22p\n", &Y) !=
	printf("good%22p\n", &Y))
		errormsg();

	if(ft_printf("1 = %d\n", 0) !=
	printf("1 = %d\n", 0))
		errormsg();

	if (ft_printf("hello%06d\n", 0b10) !=
	printf("hello%06d\n", 0b10))
		errormsg();

	if (ft_printf("9 => [%-*d %s]\n",12,9, "aiueo") !=
	printf("9 => [%-*d %s]\n",12,9, "aiueo"))
		errormsg();

	if (ft_printf("%+6d\n", 1) !=
	printf("%+6d\n", 1))
		errormsg();

	if (ft_printf("%-6d\n", 1) !=
	printf("%-6d\n", 1))
		errormsg();

	char v = -12;
	if (ft_printf("h = %010hhu\n", v) !=
	printf("h = %010hhu\n", v))
		errormsg();

	size_t w = 100010000100010001;
	if (ft_printf("z = %010zd\n", w) !=
	printf("z = %010zd\n", w))
		errormsg();

	if (ft_printf("%#10X\n", 1000) !=
	printf("%#10X\n", 1000))
		errormsg();

	if (ft_printf("%#16x\n", 2147483647) !=
	printf("%#16x\n", 2147483647))
		errormsg();

	if (ft_printf("\t%010ld\n", 9l) !=
	printf("\t%010ld\n", 9l))
		errormsg();

	if (ft_printf("%s\n", "hello") !=
	printf("%s\n", "hello"))
		errormsg();

	long x;
	long I;
	double R = 0;
	/* double d = 12.9909123456; */
	ft_printf("      float\n");
	if (ft_printf("%hhu  %%abcde%em%lniii\n", v, R,  &x) !=
	printf("%hhu  %%abcde%em%lniii\n", v, R, &I))
		errormsg();
	if (ft_printf("i = %ld\n", x) !=
	printf("I = %ld\n", I))
		errormsg();

	/* float sample = 0; */
	float sample = -23565.11111121987123456789876543211111111111111111111111111111111111111111111;
	float *sample1 = &sample;
	if (ft_printf("%%16.3E = %16.3E\n",*sample1) !=
	printf("%%16.3E = %16.3E\n",*sample1))
		errormsg();

	if (ft_printf("%%10.6f = %10.6f\n",*sample1) !=
	printf("%%10.6f = %10.6f\n",*sample1))
		errormsg();

	if (ft_printf("%%5.29e = %5.29e\n",*sample1) !=
	printf("%%5.29e = %5.29e\n",*sample1))
		errormsg();

	if (ft_printf("%%8.1f = %8.1f\n",*sample1) !=
	printf("%%8.1f = %8.1f\n",*sample1))
		errormsg();

	if (ft_printf("%%7.1f = %7.1e\n",*sample1) !=
	printf("%%7.1f = %7.1e\n",*sample1))
		errormsg();

	double y;
	y = 0./0.;
	ft_printf("ft %e %E", y, y);
	printf("   %e %E\n", y, y);

	ft_printf("ft %f %F", y, y);
	printf("   %f %F\n", y, y);

	ft_printf("ft %g %G", y, y);
	printf("   %g %G\n", y, y);

	y = 1./0.;
	ft_printf("ft %e %E", y, y);
	printf("   %e %E\n", y, y);

	ft_printf("ft %f %F", y, y);
	printf("   %f %F\n", y, y);

	ft_printf("ft %#.2g %#.2G", y, y);
	printf("   %#.2g %#.2G\n", y, y);

	if (ft_printf("Return Value: 8 / %llu\n",  (unsigned long long)ft_printf("%llu = 64\n", bs)) !=
	printf("Return Value: 8 / %llu\n",  (unsigned long long)printf("%llu = 64\n", bs)))
		errormsg();

	unsigned long long cc = 0;
	if (ft_printf("Return Value: 6 / %llu\n",  (unsigned long long)ft_printf("%lli = 0\n", cc)) !=
	printf("Return Value: 6 / %llu\n",  (unsigned long long)printf("%lli = 0\n", cc)))
		errormsg();

	ft_printf("%s%s\n","hh", "ii");
	printf("%s%s\n","hh", "ii");
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);

	printf("\n\n");
	ft_printf("hello, %s.\n", "gavin");
	printf("hello, %s.\n", "gavin");
	ft_printf("%.*p\n", -3, 0);
	printf("%.*p\n", -3, 0);
	ft_printf("%.*X\n", -3, 12345);
	printf("%.*X\n", -3, 12345);
	ft_printf("%0.i\n", NULL);
	printf("%0.i\n", NULL);

}
