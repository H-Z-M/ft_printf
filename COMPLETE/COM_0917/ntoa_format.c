/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntoa_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:20:22 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/17 11:50:31 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ntoa_format_hash(char *buf, size_t len, t_format *fmt)
{
	if (!(fmt->flags & FLAGS_PRECISION) && len
		&& ((len == fmt->precision) || (len == fmt->width)))
	{
		len--;
		if (len && (fmt->base == 16))
			len--;
	}
	if (fmt->base == 16 && fmt->flags & FLAGS_UPPERCASE)
		buf[len++] = 'X';
	else if (fmt->base == 16)
		buf[len++] = 'x';
	else if (fmt->base == 2)
		buf[len++] = 'b';
	buf[len++] = '0';
	return (len);
}

size_t	ntoa_format(char *buf, size_t idx, size_t len, t_format *fmt)
{
	if ((!(fmt->flags & FLAGS_MINUS_WIDTH) && fmt->flags & FLAGS_ZEROPAD)
		|| fmt->precision || !(fmt->flags & FLAGS_LEFT))
	{
		if (fmt->flags & FLAGS_ZEROPAD)
			while (len < fmt->width)
				buf[len++] = '0';
		while (len < fmt->precision)
			buf[len++] = '0';
	}
	if (fmt->flags & FLAGS_HASH)
		len = ntoa_format_hash(buf, len, fmt);
	if (fmt->negative)
		buf[len++] = '-';
	else if (fmt->flags & FLAGS_PLUS)
		buf[len++] = '+';
	else if (fmt->flags & FLAGS_SPACE)
		buf[len++] = ' ';
	return (out_rev(idx, buf, len, fmt));
}
