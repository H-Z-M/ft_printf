/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntoa_ulong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:20:51 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/17 16:13:27 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ntoa_ulong_value_len(size_t len, unsigned long value, t_format *fmt)
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
	return (ntoa_format_len(len, fmt));
}

size_t	ntoa_ulong(size_t idx, unsigned long value, t_format *fmt)
{
	char			*buf;
	char			digit;
	size_t			len;

	len = 0;
	len = ntoa_ulong_value_len(len, value, fmt);
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
