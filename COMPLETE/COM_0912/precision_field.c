#include "ft_printf.h"

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
