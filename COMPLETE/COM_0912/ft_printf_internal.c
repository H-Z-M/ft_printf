#include "ft_printf.h"

/*30line*/
/* out_char((char)0, ft->idx < ft->maxlen ? ft->idx : ft->maxlen - 1); */
void	ft_printf_internal(const char *format, va_list va, t_format *fmt)
{
	while (*format)
	{
		if (*format != '%')
		{
			out_char(*format, fmt->idx++);
			format++;
			continue ;
		}
		else
			format++;
		if (*format == '%')
		{
			out_char('%', fmt->idx++);
			format++;
		}
		else
		{
			format = ft_flags(format, fmt);
			format = ft_width(format, va, fmt);
			format = ft_precision(format, va, fmt);
			format = ft_length(format, fmt);
			format = ft_type(format, va, fmt);
		}
	}
}
