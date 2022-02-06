/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:20:51 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/12 10:46:41 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_format_hash_len(size_t len, t_format *fmt)
{
	if (len && (len == fmt->precision || len == fmt->width))
	{
		len--;
		if (fmt->base == 16)
			len--;
	}
	if (fmt->base == 16 && fmt->flags & FLAGS_UPPERCASE)
		len++;
	else if (fmt->base == 16)
		len++;
	len++;
	return (len);
}

size_t	ft_format_len(size_t len, t_format *fmt)
{
	if (fmt->flags & FLAGS_ZEROPAD
		|| fmt->precision || !(fmt->flags & FLAGS_LEFT))
	{
		if (fmt->width && fmt->flags & FLAGS_ZEROPAD
			&& (fmt->negative || (fmt->flags & (FLAGS_PLUS | FLAGS_SPACE))))
			fmt->width--;
		if (fmt->flags & FLAGS_ZEROPAD)
			while (len < fmt->width)
				len++;
		while (len < fmt->precision)
			len++;
	}
	if (fmt->flags & FLAGS_HASH)
		len = ft_format_hash_len(len, fmt);
	if (fmt->negative)
		len++;
	else if (fmt->flags & FLAGS_PLUS)
		len++;
	else if (fmt->flags & FLAGS_SPACE)
		len++;
	return (len);
}

size_t	ft_value_len(unsigned long value, t_format *fmt)
{
	size_t	len;

	len = 0;
	if (!value && !(fmt->flags & FLAGS_PTR))
		fmt->flags &= ~FLAGS_HASH;
	if (!value && (!(fmt->flags & FLAGS_PRECISION)))
		len++;
	while (value)
	{
		len++;
		value /= fmt->base;
	}
	return (ft_format_len(len, fmt));
}
