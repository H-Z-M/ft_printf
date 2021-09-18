#include "ft_printf.h"

const char	*ft_type_char(const char *format, va_list va, t_format *fmt)
{
	char			c;
	unsigned int	i;

	i = 1;
	if (!(fmt->flags & FLAGS_LEFT))
		while (i++ < fmt->width)
			out_char(' ', fmt->idx++);
	c = (char)va_arg(va, int);
	out_char(c, fmt->idx++);
	if (fmt->flags & FLAGS_LEFT)
		while (i++ < fmt->width)
			out_char(' ', fmt->idx++);
	format++;
	return (format);
}

const char	*ft_type_str(const char *format, va_list va, t_format *fmt)
{
	char			*p;
	unsigned int	i;

	p = va_arg(va, char *);
	if (p == NULL)
		p = "(null)";
	if (fmt->precision)
		i = ft_strnlen(p, fmt->precision);
	else
		i = ft_strnlen(p, (size_t)(-1));
	if (fmt->flags & FLAGS_MINUS_PRECISION)
		fmt->precision = PRINTF_NTOA_BUFFER_SIZE;
	if (fmt->flags & FLAGS_PRECISION)
		if (i >= fmt->precision)
			i = fmt->precision;
	if (!(fmt->flags & FLAGS_LEFT))
		while (i++ < fmt->width)
			out_char(' ', fmt->idx++);
	while ((*p != 0) && (!(fmt->flags & FLAGS_PRECISION) || fmt->precision--))
		out_char(*(p++), fmt->idx++);
	if (fmt->flags & FLAGS_LEFT)
		while (i++ < fmt->width)
			out_char(' ', fmt->idx++);
	format++;
	return (format);
}

const char	*ft_type_ptr(const char *format, va_list va, t_format *fmt)
{
	unsigned long	p;

	p = (unsigned long)va_arg(va, void *);

	/* if (!p) */
	fmt->flags |= FLAGS_HASH;

	fmt->negative = FALSE;
	fmt->base = 16;
	fmt->idx = ntoa_long(fmt->idx, p, fmt);
	format++;
	return (format);
}

const char	*ft_type_f(const char *format, va_list va, t_format *fmt)
{
	if (*format == 'f' || *format == 'F')
	{
		if (*format == 'F')
			fmt->flags |= FLAGS_UPPERCASE;
		fmt->idx = ftoa(fmt->idx, va_arg(va, double), fmt);
		format++;
	}
	if (*format == 'e' || *format == 'E' || *format == 'g' || *format == 'G')
	{
		if ((*format == 'g') || (*format == 'G'))
			fmt->flags |= FLAGS_ADAPT_EXP;
		if ((*format == 'E') || (*format == 'G'))
			fmt->flags |= FLAGS_UPPERCASE;
		fmt->idx = etoa(fmt->idx, va_arg(va, double), fmt);
		format++;
	}
	return (format);
}

const char	*ft_type_n(const char *format, va_list va, t_format *fmt)
{
	long	*prt_long;
	int		*ptr_int;

	if (fmt->qualifier == 'l')
	{
		prt_long = va_arg(va, long *);
		*prt_long = fmt->idx;
	}
	else
	{
		ptr_int = va_arg(va, int *);
		*ptr_int = fmt->idx;
	}
	format++;
	return (format);
}
