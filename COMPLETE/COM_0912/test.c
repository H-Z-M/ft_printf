#include <fcntl.h>
#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *format, ...);

/* #ifdef ac */
/* #define PRINTF(params) { \ */
/* 	int actual = ft_printf params; \ */
/* 	printf("  [%d]\n", actual); \ */
/* } */
/* #else */
/* #define PRINTF(params) { \ */
/* 	int expected =  printf params; \ */
/* 	printf("  [%d]\n", expected); \ */
/* } */
/* #endif */

#define PRINTF(params) { \
	int actual = ft_printf params; NL; \
	int expected =  printf params; NL; \
	if (actual != expected) \
		printf("----------diff---------\nac %d, ex %d\n", actual, expected); \
}
#define NL printf("\n")

int main()
{

	/* int wstatus; */
	/* int should_run = 1; */
	char *null_str = NULL;

	printf("----------basic----------\n");
	PRINTF(("%c", 'a'));
	PRINTF(("%c%c%c*", '\0', '1', 1));
	PRINTF(("%c small string", 'a'));
	PRINTF(("%c small string", '\0'));
	PRINTF(("the char is: %c", 'a'));
	PRINTF(("the char is: %c", '\0'));
	PRINTF(("n%cs", 'a'));
	PRINTF(("%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o'));
	PRINTF(("l%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o'));
	PRINTF(("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0'));
	NL;

	PRINTF(("%s", ""));
	PRINTF(("this is a %s", "test"));
	PRINTF(("this is 1 %s with %s %s", "test", "multiple", "strings"));
	PRINTF(("%s%s%s%s", "This ", "is", " an ugly ", "test"));
	PRINTF(("%s", "This is a rather simple test."));
	PRINTF(("%s", "-2"));
	PRINTF(("%s", "-24"));
	PRINTF(("%s", "-stop"));
	PRINTF(("%s", "-0003"));
	PRINTF(("%s", "000-0003"));
	PRINTF(("%s", "0x42"));
	PRINTF(("%s", "0x0000042"));
	PRINTF(("some naugty tests: %s", "0000%"));
	PRINTF(("some naugty tests: %s", "    %"));
	PRINTF(("some naugty tests: %s", "%000"));
	PRINTF(("%s", null_str));
	PRINTF(("%s everywhere", null_str));
	PRINTF(("everywhere %s", null_str));
	PRINTF(("%s", "h"));
	PRINTF(("t%st%s", "a", "u"));
	PRINTF(("%s%s%s%s%s%s", "a", "i", "u", "e", "o", "l"));
	NL;

	int test = 42;
	PRINTF(("%p", &test));
	PRINTF(("%p is a virtual memory address", &test));
	PRINTF(("The address of the answer is %p", &test));
	PRINTF(("The address is %p, so what?", &test));
	int *ptr = &test;
	PRINTF(("A pointer at %p points to %p", &test, &ptr));
	PRINTF(("This %p is a very strange address", (void *)(long int)test));
	char *mallocked = malloc(2);
	PRINTF(("This %p is an address from the heap", mallocked)); free(mallocked);
	PRINTF(("%p", NULL));
	PRINTF(("The NULL macro represents the %p address", NULL));
	PRINTF(("This %p is even stranger", (void *)-1));
	NL;

	PRINTF(("%d", 0));
	PRINTF(("%d", 10));
	PRINTF(("%d, %d", 10, 20));
	PRINTF(("%d%d%d%d", 10, 20, 30, 5));
	PRINTF(("%d %d", 2147483647, (int)-2147483648));
	PRINTF(("42 - 84 is %d", -42));
	PRINTF(("%d C is the lowest temperature in the universe", -273));
	PRINTF(("%dxC is the lowest temperature in the universe", -273));
	PRINTF(("%dsC is the lowest temperature in the universe", -273));
	PRINTF(("%dpC is the lowest temperature in the universe", -273));
	NL;

	PRINTF(("%i", 0));
	PRINTF(("%i", 10));
	PRINTF(("%i, %i", 10, 23));
	PRINTF(("%i%i%i%i%i%i%i", 10, 23, -2, 37, 200, -9999, 977779));
	PRINTF(("%i %i", 2147483647, (int)-2147483648));
	PRINTF(("%iq%i", 21447, -21648));
	NL;

	PRINTF(("%u", 42));
	PRINTF(("%u", 0));
	PRINTF(("%u", 2147483647));
	PRINTF(("%u", (unsigned int)2147483648));
	PRINTF(("%u", (unsigned int)3147983649));
	PRINTF(("%u", (unsigned int)4294967295));
	PRINTF(("%u to the power of %u is %u", 2, 32, (unsigned int)4294967295));
	PRINTF(("%u%u%u%u", (unsigned int)429896724, 0, 32, (unsigned int)4294967295));
	NL;

	PRINTF(("%x", 0));
	PRINTF(("%x", 1));
	PRINTF(("%x", 10));
	PRINTF(("%x", 16));
	PRINTF(("%x", 160));
	PRINTF(("%x", 255));
	PRINTF(("%x", 256));
	PRINTF(("%x", 3735929054u));
	PRINTF(("the password is %x", 3735929054u));
	PRINTF(("%x is the definitive answer", 66u));
	PRINTF(("this is the real number: %x", -1u));
	NL;

	PRINTF(("%X", 0));
	PRINTF(("%X", 1));
	PRINTF(("%X", 10));
	PRINTF(("%X", 16));
	PRINTF(("%X", 160));
	PRINTF(("%X", 255));
	PRINTF(("%X", 256));
	PRINTF(("%X", (unsigned int)3735929054));
	PRINTF(("the password is %X", (unsigned int)3735929054));
	PRINTF(("%X is the definitive answer", (unsigned int)66));
	PRINTF(("this is the real number: %X", (unsigned int)-1));
	NL;

	PRINTF(("%%"));
	PRINTF(("100%%"));
	PRINTF(("%%p is how you print a pointer in printf"));
	PRINTF(("the '%%%%' is used to print a %% in printf"));
	PRINTF(("%%%%%%%%%%%%%%%%"));
	PRINTF(("%%c%%s%%p%%d%%i%%u%%x%%X%%"));
	NL;

	printf("----------mix----------\n");
	PRINTF(("%c - %s - %p %d - %i - %u - %x %X %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000));
	PRINTF(("%c - %s - %p %d - %i - %u - %x %X %%", '\0', "test", (void *)-1, 20, -20, -1, -1, 200000000));
	PRINTF(("%c - %s - %p %d - %i - %u - %x %X %%", 'c', "", (void *)-1, 20, -20, -1, -1, 200000000));
	PRINTF(("%i - %s - %p %d - %c - %u - %x %X %%", 20, "", (void *)-1, '\0', -20, -1, -1, 200000000));
	PRINTF(("%c - %s - %p %d - %i - %u - %x %X %%", 'b', null_str, NULL, 20, -20, -1, -1, 200000000));
	PRINTF(("%c %s - %p - %d - %i %u - %x - %X %%", '\0', null_str, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000));
	NL;

	printf("----------width----------\n");
	PRINTF(("%1c", 'a'))
	PRINTF(("%1c", '\0'))
	PRINTF(("%10c", 'b'))
	PRINTF(("%10c", '\0'))
	PRINTF(("%2c", 'c'))
	PRINTF(("there are 15 spaces between this text and the next char%15c", 'd'))
	PRINTF(("%5chis paragraph is indented", 't'))
	PRINTF(("%5c now you see", '\0'))
	PRINTF(("The number %7c represents luck", '7'))
	NL;

	PRINTF(("%1s", "a"));
	PRINTF(("%1s", "abc"));
	PRINTF(("%7s", "a"));
	PRINTF(("%7s", "abc"));
	PRINTF(("%1s", "-42"));
	PRINTF(("%2s", "-42"));
	PRINTF(("%3s", "-42"));
	PRINTF(("%4s", "-42"));
	PRINTF(("%5s", "-42"));
	PRINTF(("%6s", "-42"));
	PRINTF(("%1s", null_str));
	PRINTF(("%2s", null_str));
	PRINTF(("%5s", null_str));
	PRINTF(("%6s", null_str));
	PRINTF(("%7s", null_str));
	PRINTF(("%7s is as easy as %13s", "abc", "123"));
	PRINTF(("%13s are the three first letter of the %3s", "a, b and c", "alphabet"));
	PRINTF(("%s%13s%42s%3s", "a, b and c", " are letters", " of the", " alphabet"));
	PRINTF(("%sc%13sd%42sp%3sx", "a, b and c", " are letters", " of the", " alphabet"));
	PRINTF(("%sc%13sd%42sp%3sx", "a, b and c", " are letters", " of the", " alphabet"));
	NL;

	char c;
	PRINTF(("%1p", &c));
	PRINTF(("%30p", &c));
	PRINTF(("%12p", (void *)0x7ffe6b8e60c6));
	PRINTF(("%13p", (void *)0x7ffe6b8e60c5));
	PRINTF(("%14p", (void *)0x7ffe6b8e60c4));
	PRINTF(("the address is %12p", (void *)0x7ffe6b8e60c7));
	PRINTF(("the address is %13p", (void *)0x7ffe6b8e60c8));
	PRINTF(("the address is %14p", (void *)0x7ffe6b8e60c9));
	PRINTF(("the address is %1p", (void *)0));
	PRINTF(("the address is %2p", (void *)0));
	PRINTF(("the address is %3p", (void *)0));
	PRINTF(("the address is %4p", (void *)0));
	PRINTF(("the address is %8p", (void *)0));
	PRINTF(("%12p is the address", (void *)0x7ffe6b8e60c7));
	PRINTF(("%13p is the address", (void *)0x7ffe6b8e60c8));
	PRINTF(("%14p is the address", (void *)0x7ffe6b8e60c9));
	PRINTF(("%1p is the address", (void *)0));
	PRINTF(("%2p is the address", (void *)0));
	PRINTF(("%3p is the address", (void *)0));
	PRINTF(("%4p is the address", (void *)0));
	PRINTF(("%8p is the address", (void *)0));
	NL;

	return 0;
	printf("%d\n", CONSECUTIVE_ZERO | FLAGS_MINUS_PRECISION | FLAGS_ASTER | FLAGS_ASTER2 | FLAGS_PRECISION);
	printf("%d\n", CONSECUTIVE_ZERO | FLAGS_MINUS_PRECISION | FLAGS_ASTER | FLAGS_ASTER2 | FLAGS_PRECISION | FLAGS_UPPERCASE);
}
