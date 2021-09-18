#include "ft_printf.h"

const char	*ft_lenght2(const char *format, t_format *fmt)
{
	if (*format == 't')
	{
		if (sizeof(ptrdiff_t) == sizeof(long))
			fmt->flags |= FLAGS_LONG;
		else
			fmt->flags |= FLAGS_LONG_LONG;
		format++;
	}
	else if (*format == 'j')
	{
		if (sizeof(intmax_t) == sizeof(long))
			fmt->flags |= FLAGS_LONG;
		else
			fmt->flags |= FLAGS_LONG_LONG;
		format++;
	}
	else if (*format == 'z')
	{
		if (sizeof(size_t) == sizeof(long))
			fmt->flags |= FLAGS_LONG;
		else
			fmt->flags |= FLAGS_LONG_LONG;
		format++;
	}
	return (format);
}

/* if (*format == 'h' || *format == 'l') */
/* fmt->qualifier = *format; */
const char	*ft_length(const char *format, t_format *fmt)
{
	if (*format == 'l')
	{
		fmt->qualifier = *format;
		fmt->flags |= FLAGS_LONG;
		format++;
		if (*format == 'l')
		{
			fmt->flags |= FLAGS_LONG_LONG;
			format++;
		}
	}
	else if (*format == 'h')
	{
		fmt->qualifier = *format;
		fmt->flags |= FLAGS_SHORT;
		format++;
		if (*format == 'h')
		{
			fmt->flags |= FLAGS_CHAR;
			format++;
		}
	}
	else if (*format == 't' || *format == 'j' || *format == 'z')
		format = ft_lenght2(format, fmt);
	return (format);
}
