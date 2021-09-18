#include "ft_printf.h"

/* #include "/home/sss/UTIL/leakdetect.h" */
/* #define malloc(s) leak_detect_malloc(s, __FILE__, __LINE__) */
/* #define free leak_detect_free */

/* typedef struct s_ftoa */
/* { */
/* 	unsigned long long	whole; */
/* 	int					negative; */
/* 	size_t				len; */
/* 	double				diff; */
/* 	unsigned long long	frac; */
/* }				t_ftoa; */
void	ftoa5(t_format *fmt, t_ftoa *ftoa, int foo)
{
	while (ftoa->len < PRINTF_FTOA_BUFFER_SIZE)
	{
		fmt->buf[ftoa->len++] = (char)(48 + (ftoa->whole % 10));
		foo = (ftoa->whole /= 10);
		if (!foo)
			break ;
	}
	if (!(fmt->flags & FLAGS_LEFT) && (fmt->flags & FLAGS_ZEROPAD))
	{
		if (fmt->width && (fmt->negative
				|| (fmt->flags & (FLAGS_PLUS | FLAGS_SPACE))))
			fmt->width--;
		while ((ftoa->len < fmt->width) && (ftoa->len < PRINTF_FTOA_BUFFER_SIZE))
			fmt->buf[ftoa->len++] = '0';
	}
	if (ftoa->len < PRINTF_FTOA_BUFFER_SIZE)
	{
		if (ftoa->negative)
			fmt->buf[ftoa->len++] = '-';
		else if (fmt->flags & FLAGS_PLUS)
			fmt->buf[ftoa->len++] = '+';
		else if (fmt->flags & FLAGS_SPACE)
			fmt->buf[ftoa->len++] = ' ';
	}
}

void	ftoa4(double value, t_format *fmt, t_ftoa *ftoa, int foo)
{
	unsigned int	count;

	if (fmt->precision == 0)
	{
		ftoa->diff = value - (double)ftoa->whole;
		if ((!(ftoa->diff < 0.5) || (ftoa->diff > 0.5)) && (ftoa->whole & 1))
			++ftoa->whole;
	}
	else
	{
		count = fmt->precision;
		while (ftoa->len < PRINTF_FTOA_BUFFER_SIZE)
		{
			--count;
			fmt->buf[ftoa->len++] = (char)(48 + (ftoa->frac % 10));
			foo = (ftoa->frac /= 10);
			if (!foo)
				break ;
		}
		while ((ftoa->len < PRINTF_FTOA_BUFFER_SIZE) && (count-- > 0))
			fmt->buf[ftoa->len++] = '0';
		if (ftoa->len < PRINTF_FTOA_BUFFER_SIZE)
			fmt->buf[ftoa->len++] = '.';
	}
}

void	ftoa3(double value, t_format *fmt, t_ftoa *ftoa)
{
	double				tmp;
	static const double	pow[] = {1, 10, 100, 1000, 10000, 100000, 1000000,
		10000000, 100000000, 1000000000, 10000000000, 100000000000,
		1000000000000, 10000000000000, 100000000000000, 1000000000000000,
		10000000000000000, 100000000000000000, 1000000000000000000};

	ftoa->whole = (unsigned long long)value;
	tmp = (value - ftoa->whole) * pow[fmt->precision];
	ftoa->frac = (unsigned long long)tmp;
	ftoa->diff = tmp - ftoa->frac;
	if (ftoa->diff > 0.5)
	{
		++ftoa->frac;
		if (ftoa->frac >= pow[fmt->precision])
		{
			ftoa->frac = 0;
			++ftoa->whole;
		}
	}
	else if (ftoa->diff < 0.5)
		;
	else if ((ftoa->frac == 0) || (ftoa->frac & 1))
		++ftoa->frac;
}

double	ftoa2(double value, t_format *fmt, t_ftoa *ftoa)
{
	ftoa->negative = FALSE;
	if (value < 0)
	{
		ftoa->negative = TRUE;
		value = 0 - value;
	}
	ftoa->len = 0;
	if (!(fmt->flags & FLAGS_PRECISION) || (fmt->flags & FLAGS_MINUS_PRECISION))
		fmt->precision = PRINTF_DEFAULT_FLOAT_PRECISION;
	while ((ftoa->len < PRINTF_FTOA_BUFFER_SIZE) && (fmt->precision > 18))
	{
		fmt->buf[ftoa->len++] = '0';
		fmt->precision--;
	}
	return (value);
}

size_t	ftoa(size_t idx, double value, t_format *fmt)
{
	int		foo;
	t_ftoa	*ftoa;

	ftoa = (t_ftoa *)malloc(sizeof(t_ftoa));
	ftoa->len = 0;
	ftoa->diff = 0.0;
	if (value != value)
		return (out_rev(idx, "nan", 3, fmt));
	if (value < -DBL_MAX)
		return (out_rev(idx, "fni-", 4, fmt));
	if (value > DBL_MAX)
	{
		if (fmt->flags & FLAGS_PLUS)
			return (out_rev(idx, "fni+", 4, fmt));
		else
			return (out_rev(idx, "fni", 3, fmt));
	}
	if ((value > PRINTF_MAX_FLOAT) || (value < -PRINTF_MAX_FLOAT))
		return (etoa(idx, value, fmt));
	value = ftoa2(value, fmt, ftoa);
	ftoa3(value, fmt, ftoa);
	foo = 0;
	ftoa4(value, fmt, ftoa, foo);
	ftoa5(fmt, ftoa, foo);
	free(ftoa);
	return (out_rev(idx, fmt->buf, ftoa->len, fmt));
}
