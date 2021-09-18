/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_field2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:15:17 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/17 16:14:45 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_char(const char **format, va_list va, t_format *fmt)
{
	char			c;
	unsigned int	i;

	i = 1;
	if (!(fmt->flags & FLAGS_LEFT))
		while (i++ < fmt->width)
			out_char(' ', fmt->idx++);
	c = (char)va_arg(va, int);
	out_char(c, fmt->idx++);
	if (fmt->flags & FLAGS_LEFT)
		while (i++ < fmt->width)
			out_char(' ', fmt->idx++);
	(*format)++;
}

void	ft_type_str(const char **format, va_list va, t_format *fmt)
{
	char			*p;
	unsigned int	i;

	p = va_arg(va, char *);
	if (p == NULL)
		p = "(null)";
	if (fmt->precision)
		i = ft_strnlen(p, fmt->precision);
	else
		i = ft_strnlen(p, INT_MAX);
	if (fmt->flags & FLAGS_PRECISION && i >= fmt->precision)
		i = fmt->precision;
	if (!(fmt->flags & FLAGS_LEFT))
		while (i++ < fmt->width)
			out_char(' ', fmt->idx++);
	while ((*p != 0) && (!(fmt->flags & FLAGS_PRECISION) || fmt->precision--))
		out_char(*(p++), fmt->idx++);
	if (fmt->flags & FLAGS_LEFT)
		while (i++ < fmt->width)
			out_char(' ', fmt->idx++);
	(*format)++;
}

void	ft_type_ptr(const char **format, va_list va, t_format *fmt)
{
	unsigned long	p;
	unsigned long	tmp;
	unsigned long	i;

	p = (unsigned long)va_arg(va, void *);
	fmt->flags |= (FLAGS_HASH | FLAGS_PTR);
	fmt->negative = FALSE;
	fmt->base = 16;
	tmp = p;
	i = 0;
	while (tmp)
	{
		tmp /= fmt->base;
		i++;
	}
	if (i == fmt->width || (!p && fmt->width == 1))
		fmt->width = 0;
	fmt->idx = ntoa_ulong(fmt->idx, p, fmt);
	(*format)++;
}
