#include "ft_printf.h"

size_t	ntoa_format_hash(size_t len, t_format *fmt)
{
	if (fmt->flags & FLAGS_HASH)
	{
		if (!(fmt->flags & FLAGS_PRECISION) && len
			&& ((len == fmt->precision) || (len == fmt->width)))
		{
			len--;
			if (len && (fmt->base == 16))
				len--;
		}
		if ((fmt->base == 16) && !(fmt->flags & FLAGS_UPPERCASE)
			&& (len < PRINTF_NTOA_BUFFER_SIZE))
			fmt->buf[len++] = 'x';
		else if ((fmt->base == 16) && (fmt->flags & FLAGS_UPPERCASE)
			&& (len < PRINTF_NTOA_BUFFER_SIZE))
			fmt->buf[len++] = 'X';
		else if ((fmt->base == 2) && (len < PRINTF_NTOA_BUFFER_SIZE))
			fmt->buf[len++] = 'b';
		if (len < PRINTF_NTOA_BUFFER_SIZE)
			fmt->buf[len++] = '0';
	}
	return (len);
}

/*
* 111616 = CONSECUTIVE_ZERO | FLAGS_MINUS_PRECISION
*        | FLAGS_ASTER | FLAGS_ASTER2 | FLAGS_PRECISION
* 111648 = CONSECUTIVE_ZERO | FLAGS_MINUS_PRECISION
*        | FLAGS_ASTER | FLAGS_ASTER2 | FLAGS_PRECISION | FLAGS_UPPERCASE
*/
size_t	ntoa_format(size_t idx, size_t len, t_format *fmt)
{
	if ((!(fmt->flags & FLAGS_MINUS_WIDTH) && fmt->flags & FLAGS_ZEROPAD)
		|| fmt->precision || !(fmt->flags & FLAGS_LEFT))
	{
		if (fmt->flags == 111616 || fmt->flags == 111648)
			fmt->flags |= FLAGS_ZEROPAD;
		if (fmt->width && (fmt->flags & FLAGS_ZEROPAD)
			&& (fmt->negative || (fmt->flags & (FLAGS_PLUS | FLAGS_SPACE))))
			fmt->width--;
		if (fmt->flags & FLAGS_ZEROPAD)
			while ((len < fmt->width) && (len < PRINTF_NTOA_BUFFER_SIZE))
				fmt->buf[len++] = '0';
		while ((len < fmt->precision) && (len < PRINTF_NTOA_BUFFER_SIZE))
			fmt->buf[len++] = '0';
	}
	len = ntoa_format_hash(len, fmt);
	if (len < PRINTF_NTOA_BUFFER_SIZE)
	{
		if (fmt->negative)
			fmt->buf[len++] = '-';
		else if (fmt->flags & FLAGS_PLUS)
			fmt->buf[len++] = '+';
		else if (fmt->flags & FLAGS_SPACE)
			fmt->buf[len++] = ' ';
	}
	return (out_rev(idx, fmt->buf, len, fmt));
}
