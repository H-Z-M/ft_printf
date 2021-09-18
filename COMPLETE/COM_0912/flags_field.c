#include "ft_printf.h"

const char	*consecutive_zero(const char *format, t_format *fmt)
{
	fmt->flags |= FLAGS_LEFT;
	fmt->flags &= ~FLAGS_ZEROPAD;
	format++;
	return (format);
}

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
