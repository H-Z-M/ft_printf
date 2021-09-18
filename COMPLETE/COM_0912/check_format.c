#include "ft_printf.h"

const char	*ft_flags(const char *format, t_format *fmt)
{
	fmt->flags = 0;
	while (1)
	{
		if (*format == '0')
		{
			if (fmt->flags & CONSECUTIVE_ZERO)
			{
				format = consecutive_zero(format, fmt);
				continue ;
			}
			fmt->flags |= (FLAGS_ZEROPAD | CONSECUTIVE_ZERO);
		}
		else if (*format == '-')
			fmt->flags |= FLAGS_LEFT;
		else if (*format == '+')
			fmt->flags |= FLAGS_PLUS;
		else if (*format == ' ')
			fmt->flags |= FLAGS_SPACE;
		else if (*format == '#')
			fmt->flags |= FLAGS_HASH;
		else
			break ;
		format++;
	}
	return (format);
}

const char	*ft_width(const char *format, va_list va, t_format *fmt)
{
	int	w;

	fmt->width = 0;
	if (is_digit(*format))
		fmt->width = ft_atoi_pf(&format);
	else if (*format == '*')
	{
		w = va_arg(va, int);
		if (w < 0)
		{
			fmt->flags |= (FLAGS_LEFT | FLAGS_MINUS_WIDTH);
			fmt->width = (unsigned int)(-w);
		}
		else
			fmt->width = (unsigned int)w;
		fmt->flags |= FLAGS_ASTER;
		format++;
	}
	return (format);
}

/* 77
* else
* {
* 	fmt->precision = 0;
* 	fmt->flags |= FLAGS_MINUS_PRECISION;
* }
*/
const char	*ft_precision(const char *format, va_list va, t_format *fmt)
{
	int	prec;

	fmt->precision = 0;
	if (*format == '.')
	{
		fmt->flags |= FLAGS_PRECISION;
		format++;
		if (is_digit(*format))
			fmt->precision = ft_atoi_pf(&format);
		else if (*format == '*')
		{
			prec = va_arg(va, int);
			if (prec >= 0)
				fmt->precision = (unsigned int)prec;
			else
				fmt->flags |= FLAGS_MINUS_PRECISION;
			fmt->flags |= FLAGS_ASTER2;
			format++;
		}
	}
	return (format);
}

	/* if (*format == 'j') */
	/* { */
	/* 	if (sizeof(intmax_t) == sizeof(long)) */
	/* 		ft->flags |= FLAGS_LONG; */
	/* 	else */
	/* 		ft->flags |= FLAGS_LONG_LONG; */
	/* 	format++; */
	/* } */
const char	*ft_lenght2(const char *format, t_format *fmt)
{
	if (*format == 'j')
	{
		fmt->flags |= FLAGS_LONG_LONG;
		format++;
	}
	if (*format == 'z')
	{
		if (sizeof(size_t) == sizeof(long))
			fmt->flags |= FLAGS_LONG;
		else
			fmt->flags |= FLAGS_LONG_LONG;
		format++;
	}
	return (format);
}

const char	*ft_length(const char *format, t_format *fmt)
{
	if (*format == 'h' || *format == 'l')
		fmt->qualifier = *format;
	if (*format == 'l')
	{
		fmt->flags |= FLAGS_LONG;
		format++;
		if (*format == 'l')
		{
			fmt->flags |= FLAGS_LONG_LONG;
			format++;
		}
	}
	if (*format == 'h')
	{
		fmt->flags |= FLAGS_SHORT;
		format++;
		if (*format == 'h')
		{
			fmt->flags |= FLAGS_CHAR;
			format++;
		}
	}
	if (*format == 'j' || *format == 'z')
		format = ft_lenght2(format, fmt);
	return (format);
}
