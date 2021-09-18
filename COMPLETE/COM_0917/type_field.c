/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:14:59 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/17 09:50:54 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_signed2(va_list va, t_format *fmt)
{
	long	value;

	if (fmt->flags & FLAGS_CHAR)
		value = (char)va_arg(va, int);
	else if (fmt->flags & FLAGS_SHORT)
		value = (short int)va_arg(va, int);
	else
		value = va_arg(va, int);
	fmt->negative = value < 0;
	if (fmt->negative)
		value = 0 - value;
	fmt->idx = ntoa_long(fmt->idx, (unsigned int)value, fmt);
}

void	ft_type_signed(va_list va, t_format *fmt)
{
	long long	value;

	if (fmt->flags & FLAGS_LONG_LONG)
	{
		value = va_arg(va, long long);
		fmt->negative = value < 0;
		if (fmt->negative)
			value = 0 - value;
		fmt->idx = ntoa_long_long(fmt->idx, (unsigned long long)value, fmt);
	}
	else if (fmt->flags & FLAGS_LONG)
	{
		value = va_arg(va, long);
		fmt->negative = value < 0;
		if (fmt->negative)
			value = 0 - value;
		fmt->idx = ntoa_long(fmt->idx, (unsigned long)value, fmt);
	}
	else
		ft_type_signed2(va, fmt);
}

void	ft_type_unsigned(va_list va, t_format *fmt)
{
	unsigned int	value;

	fmt->negative = FALSE;
	if (fmt->flags & FLAGS_LONG_LONG)
		fmt->idx = ntoa_long_long(fmt->idx,
				va_arg(va, unsigned long long), fmt);
	else if (fmt->flags & FLAGS_LONG)
		fmt->idx = ntoa_long(fmt->idx, va_arg(va, unsigned long), fmt);
	else
	{
		if (fmt->flags & FLAGS_CHAR)
			value = (unsigned char)va_arg(va, unsigned int);
		else if (fmt->flags & FLAGS_SHORT)
			value = (unsigned short int)va_arg(va, unsigned int);
		else
			value = va_arg(va, unsigned int);
		fmt->idx = ntoa_long(fmt->idx, value, fmt);
	}
}

void	ft_type_digit(const char **format, va_list va, t_format *fmt)
{
	ft_base_num(*format, fmt);
	if ((**format != 'i') && (**format != 'd'))
		fmt->flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
	if (fmt->flags & FLAGS_PRECISION)
		fmt->flags &= ~FLAGS_ZEROPAD;
	if ((**format == 'i') || (**format == 'd'))
		ft_type_signed(va, fmt);
	else
		ft_type_unsigned(va, fmt);
	(*format)++;
}

void	ft_type(const char **format, va_list va, t_format *fmt)
{
	if (**format == 'd' || **format == 'i' || **format == 'u'
		|| **format == 'x' || **format == 'X' || **format == 'o'
		|| **format == 'b')
		ft_type_digit(format, va, fmt);
	else if (**format == 'n')
		ft_type_n(format, va, fmt);
	else if (**format == 'f' || **format == 'F' || **format == 'e'
		|| **format == 'E' || **format == 'g' || **format == 'G')
		ft_type_f(format, va, fmt);
	else if (**format == 'c')
		ft_type_char(format, va, fmt);
	else if (**format == 's')
		ft_type_str(format, va, fmt);
	else if (**format == 'p')
		ft_type_ptr(format, va, fmt);
	else
		ft_type_else_format(format, va, fmt);
}
