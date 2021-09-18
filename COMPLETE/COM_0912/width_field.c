#include "ft_printf.h"

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
