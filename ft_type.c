/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:14:59 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/12 09:42:26 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_base_num(const char *format, t_format *fmt)
{
	if (*format == 'x' || *format == 'X')
	{
		fmt->base = 16;
		if (*format == 'X')
			fmt->flags |= FLAGS_UPPERCASE;
	}
	else
	{
		fmt->base = 10;
		fmt->flags &= ~FLAGS_HASH;
	}
}

void	ft_type_digit(const char **format, va_list va, t_format *fmt)
{
	int				value;
	unsigned int	value_u;

	ft_base_num(*format, fmt);
	if ((**format != 'i') && (**format != 'd'))
		fmt->flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
	if (fmt->flags & FLAGS_PRECISION)
		fmt->flags &= ~FLAGS_ZEROPAD;
	if ((**format == 'i') || (**format == 'd'))
	{
		value = va_arg(va, int);
		fmt->negative = value < 0;
		if (fmt->negative)
			value *= -1;
		ft_forming(value, fmt, TRUE);
	}
	else
	{
		fmt->negative = FALSE;
		value_u = va_arg(va, unsigned int);
		ft_forming(value_u, fmt, TRUE);
	}
	(*format)++;
}

void	ft_type(const char **format, va_list va, t_format *fmt)
{
	if (fmt->error)
		return ;
	if (fmt->buf_len)
		ft_out_buf(fmt);
	if (**format == 'd' || **format == 'i' || **format == 'u'
		|| **format == 'x' || **format == 'X')
		ft_type_digit(format, va, fmt);
	else if (**format == 'c')
		ft_type_char(format, va, fmt);
	else if (**format == 's')
		ft_type_str(format, va, fmt);
	else if (**format == 'p')
		ft_type_ptr(format, va, fmt);
	else
		ft_type_else(format, fmt);
}
