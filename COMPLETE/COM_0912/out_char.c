#include "ft_printf.h"

void	out_char(char ch, size_t idx)
{
	(void)idx;
	ft_putchar(ch);
}

size_t	out_rev(size_t idx, const char *buf, size_t len, t_format *fmt)
{
	size_t	i;
	size_t	start_idx;

	i = len;
	start_idx = idx;
	if (!(fmt->flags & FLAGS_LEFT) && !(fmt->flags & FLAGS_ZEROPAD))
	{
		while (i < fmt->width)
		{
			out_char(' ', idx++);
			i++;
		}
	}
	while (len)
		out_char(buf[--len], idx++);
	if (fmt->flags & FLAGS_LEFT)
		while (idx - start_idx < fmt->width)
			out_char(' ', idx++);
	return (idx);
}
