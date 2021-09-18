#include "ft_printf.h"

size_t	ntoa_long(size_t idx, unsigned long value, t_format *fmt)
{
	char	digit;
	size_t	len;

	len = 0;
	if (!value)
		fmt->flags &= ~FLAGS_HASH;
	if (!value && (!(fmt->flags & FLAGS_PRECISION)
			|| fmt->flags & FLAGS_MINUS_PRECISION))
		fmt->buf[len++] = '0';
	if (!(fmt->flags & FLAGS_PRECISION) || value)
	{
		while (value && (len < PRINTF_NTOA_BUFFER_SIZE))
		{
			digit = (char)(value % fmt->base);
			if (digit < 10)
				fmt->buf[len++] = '0' + digit;
			else if (fmt->flags & FLAGS_UPPERCASE)
				fmt->buf[len++] = 'A' + digit - 10;
			else
				fmt->buf[len++] = 'a' + digit - 10;
			value /= fmt->base;
		}
	}
	return (ntoa_format(idx, len, fmt));
}
