/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forming.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:20:22 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/12 10:47:02 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_store_hash(char *buf, size_t idx, t_format *fmt)
{
	if (idx && (idx == fmt->precision || idx == fmt->width))
	{
		idx--;
		if (fmt->base == 16)
			idx--;
	}
	if (fmt->base == 16 && fmt->flags & FLAGS_UPPERCASE)
		buf[idx++] = 'X';
	else if (fmt->base == 16)
		buf[idx++] = 'x';
	buf[idx++] = '0';
	return (idx);
}

size_t	ft_store_flags(char *buf, size_t idx, t_format *fmt)
{
	if (fmt->flags & FLAGS_ZEROPAD
		|| fmt->precision || !(fmt->flags & FLAGS_LEFT))
	{
		if (fmt->flags & FLAGS_ZEROPAD)
			while (idx < fmt->width)
				buf[idx++] = '0';
		while (idx < fmt->precision)
			buf[idx++] = '0';
	}
	if (fmt->flags & FLAGS_HASH)
		idx = ft_store_hash(buf, idx, fmt);
	if (fmt->negative)
		buf[idx++] = '-';
	else if (fmt->flags & FLAGS_PLUS)
		buf[idx++] = '+';
	else if (fmt->flags & FLAGS_SPACE)
		buf[idx++] = ' ';
	return (idx);
}

size_t	ft_store_value(unsigned long value, char *buf, t_format *fmt)
{
	char	digit;
	size_t	idx;

	idx = 0;
	if (!value && (!(fmt->flags & FLAGS_PRECISION)))
		buf[idx++] = '0';
	while (value)
	{
		digit = (char)(value % fmt->base);
		if (digit < 10)
			buf[idx++] = '0' + digit;
		else if (fmt->flags & FLAGS_UPPERCASE)
			buf[idx++] = 'A' + digit - 10;
		else
			buf[idx++] = 'a' + digit - 10;
		value /= fmt->base;
	}
	buf[idx] = '\0';
	return (idx);
}

void	ft_forming(unsigned long value, t_format *fmt, int is_uint)
{
	char	*buf;
	size_t	idx;

	if (is_uint)
		value = (unsigned int)value;
	buf = malloc(ft_value_len(value, fmt) + 1);
	if (ft_error_check(buf, fmt))
		return ;
	idx = ft_store_value(value, buf, fmt);
	idx = ft_store_flags(buf, idx, fmt);
	ft_out_rev(buf, idx, fmt);
	free(buf);
}
