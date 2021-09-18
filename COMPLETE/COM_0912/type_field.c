#include "ft_printf.h"

const char	*ft_type_signed2(const char *format, va_list va, t_format *fmt)
{
	long	value;

	if (fmt->flags & FLAGS_CHAR)
		value = (char)va_arg(va, int);
	else if (fmt->flags & FLAGS_SHORT)
		value = (short int)va_arg(va, int);
	else
		value = va_arg(va, int);
	fmt->negative = value < 0;
	if (fmt->negative)
		value = 0 - value;
	fmt->idx = ntoa_long(fmt->idx, (unsigned int)value, fmt);
	return (format);
}

const char	*ft_type_signed(const char *format, va_list va, t_format *fmt)
{
	long long	value;

	if (fmt->flags & FLAGS_LONG_LONG)
	{
		value = va_arg(va, long long);
		fmt->negative = value < 0;
		if (fmt->negative)
			value = 0 - value;
		fmt->idx = ntoa_long_long(fmt->idx, (unsigned long long)value, fmt);
	}
	else if (fmt->flags & FLAGS_LONG)
	{
		value = va_arg(va, long);
		fmt->negative = value < 0;
		if (fmt->negative)
			value = 0 - value;
		fmt->idx = ntoa_long(fmt->idx, (unsigned long)value, fmt);
	}
	else
		ft_type_signed2(format, va, fmt);
	return (format);
}

const char	*ft_type_unsigned(const char *format, va_list va, t_format *fmt)
{
	unsigned int	value;

	if (fmt->flags & FLAGS_LONG_LONG)
	{
		fmt->negative = FALSE;
		fmt->idx = ntoa_long_long(fmt->idx, va_arg(va, unsigned long long), fmt);
	}
	else if (fmt->flags & FLAGS_LONG)
	{
		fmt->negative = FALSE;
		fmt->idx = ntoa_long(fmt->idx, va_arg(va, unsigned long), fmt);
	}
	else
	{
		if (fmt->flags & FLAGS_CHAR)
			value = (unsigned char)va_arg(va, unsigned int);
		else if (fmt->flags & FLAGS_SHORT)
			value = (unsigned short int)va_arg(va, unsigned int);
		else
			value = va_arg(va, unsigned int);
		fmt->negative = FALSE;
		fmt->idx = ntoa_long(fmt->idx, value, fmt);
	}
	return (format);
}

const char	*ft_type_digit(const char *format, va_list va, t_format *fmt)
{
	ft_base_num(format, fmt);
	if ((*format != 'i') && (*format != 'd'))
		fmt->flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
	if (fmt->flags & FLAGS_PRECISION)
		fmt->flags &= ~FLAGS_ZEROPAD;
	if ((*format == 'i') || (*format == 'd'))
		format = ft_type_signed(format, va, fmt);
	else
		format = ft_type_unsigned(format, va, fmt);
	format++;
	return (format);
}

const char	*ft_type(const char *format, va_list va, t_format *fmt)
{
	if (*format == 'd' || *format == 'i' || *format == 'u'
		|| *format == 'x' || *format == 'X' || *format == 'o' || *format == 'b')
		format = ft_type_digit(format, va, fmt);
	else if (*format == 'n')
		format = ft_type_n(format, va, fmt);
	else if (*format == 'f' || *format == 'F' || *format == 'e'
		|| *format == 'E' || *format == 'g' || *format == 'G')
		format = ft_type_f(format, va, fmt);
	else if (*format == 'c')
		format = ft_type_char(format, va, fmt);
	else if (*format == 's')
		format = ft_type_str(format, va, fmt);
	else if (*format == 'p')
		format = ft_type_ptr(format, va, fmt);
	return (format);
}
