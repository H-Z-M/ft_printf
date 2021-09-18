/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntoa_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:20:30 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/17 11:53:55 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "leakdetect.h"
#define malloc(s) leak_detect_malloc(s, __FILE__, __LINE__)
#define free leak_detect_free

size_t	ntoa_format_hash_len(size_t len, t_format *fmt)
{
	if (!(fmt->flags & FLAGS_PRECISION) && len
		&& ((len == fmt->precision) || (len == fmt->width)))
	{
		len--;
		if (len && (fmt->base == 16))
			len--;
	}
	if (fmt->base == 16 && fmt->flags & FLAGS_UPPERCASE)
		len++;
	else if (fmt->base == 16)
		len++;
	else if (fmt->base == 2)
		len++;
	len++;
	return (len);
}

size_t	ntoa_format_len(size_t len, t_format *fmt)
{
	if ((!(fmt->flags & FLAGS_MINUS_WIDTH) && fmt->flags & FLAGS_ZEROPAD)
		|| fmt->precision || !(fmt->flags & FLAGS_LEFT))
	{
		if (fmt->width && (fmt->flags & FLAGS_ZEROPAD)
			&& (fmt->negative || (fmt->flags & (FLAGS_PLUS | FLAGS_SPACE))))
			fmt->width--;
		if (fmt->flags & FLAGS_ZEROPAD)
			while (len < fmt->width)
				len++;
		while (len < fmt->precision)
			len++;
	}
	if (fmt->flags & FLAGS_HASH)
		len = ntoa_format_hash_len(len, fmt);
	if (fmt->negative)
		len++;
	else if (fmt->flags & FLAGS_PLUS)
		len++;
	else if (fmt->flags & FLAGS_SPACE)
		len++;
	return (len);
}

size_t	ntoa_l_value_len(size_t len, unsigned long value, t_format *fmt)
{
	if (!value && !(fmt->flags & FLAGS_PTR))
		fmt->flags &= ~FLAGS_HASH;
	if (!value && (!(fmt->flags & FLAGS_PRECISION)))
		len++;
	while (value)
	{
		len++;
		value /= fmt->base;
	}
	len = ntoa_format_len(len, fmt);
	return (len);
}

size_t	ntoa_long(size_t idx, unsigned long value, t_format *fmt)
{
	char	*buf;
	char	digit;
	size_t	len;

	len = 0;
	len = ntoa_l_value_len(len, value, fmt);
	buf = (char *)malloc(len + 1);
	len = 0;
	if (!value && (!(fmt->flags & FLAGS_PRECISION)))
		buf[len++] = '0';
	while (value)
	{
		digit = (char)(value % fmt->base);
		if (digit < 10)
			buf[len++] = '0' + digit;
		else if (fmt->flags & FLAGS_UPPERCASE)
			buf[len++] = 'A' + digit - 10;
		else
			buf[len++] = 'a' + digit - 10;
		value /= fmt->base;
	}
	idx = ntoa_format(buf, idx, len, fmt);
	free(buf);
	return (idx);
}
