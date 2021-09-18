/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:03:20 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/18 13:25:35 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision(const char **format, t_format *fmt)
{
	fmt->precision = 0;
	if (**format == '.')
	{
		fmt->flags |= FLAGS_PRECISION;
		(*format)++;
		if (is_digit(**format))
			fmt->precision = ft_atoi_pf(format);
	}
}

void	ft_width(const char **format, t_format *fmt)
{
	fmt->width = 0;
	if (is_digit(**format))
		fmt->width = ft_atoi_pf(format);
}

void	ft_flags(const char **format, t_format *fmt)
{
	fmt->flags = 0;
	while (1)
	{
		if (**format == '0')
			fmt->flags |= FLAGS_ZEROPAD;
		else if (**format == '-')
			fmt->flags = FLAGS_LEFT;
		else if (**format == '+')
			fmt->flags |= FLAGS_PLUS;
		else if (**format == ' ')
			fmt->flags |= FLAGS_SPACE;
		else if (**format == '#')
			fmt->flags |= FLAGS_HASH;
		else
			break ;
		(*format)++;
	}
	if (fmt->flags & FLAGS_LEFT)
		fmt->flags &= ~FLAGS_ZEROPAD;
}

void	ft_printf_internal(const char *format, va_list va, t_format *fmt)
{
	while (*format)
	{
		if (*format != '%')
		{
			out_char(*format, fmt->idx++);
			format++;
			continue ;
		}
		else
			format++;
		if (*format == '%')
		{
			out_char('%', fmt->idx++);
			format++;
		}
		else
		{
			ft_flags(&format, fmt);
			ft_width(&format, fmt);
			ft_precision(&format, fmt);
			ft_type(&format, va, fmt);
		}
	}
}

int	ft_printf(const char *format, ...)
{
	size_t		idx;
	va_list		va;
	t_format	*fmt;

	fmt = (t_format *)malloc(sizeof(t_format));
	fmt->idx = 0;
	va_start(va, format);
	ft_printf_internal(format, va, fmt);
	va_end(va);
	idx = fmt->idx;
	free(fmt);
	return (idx);
}
