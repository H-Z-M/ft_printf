/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:21:02 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/16 20:40:07 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	out_char(char ch, size_t idx)
{
	(void)idx;
	if (idx <= INT_MAX)
		ft_putchar(ch);
}

size_t	out_rev(size_t idx, const char *buf, size_t len, t_format *fmt)
{
	size_t	i;
	size_t	start_idx;

	i = len;
	start_idx = idx;
	if (!(fmt->flags & FLAGS_LEFT) && !(fmt->flags & FLAGS_ZEROPAD))
		while (i++ < fmt->width)
			out_char(' ', idx++);
	while (len)
		out_char(buf[--len], idx++);
	if (fmt->flags & FLAGS_LEFT)
		while (idx - start_idx < fmt->width)
			out_char(' ', idx++);
	return (idx);
}

void	ft_type_else_out_char(const char **format, t_format *fmt)
{
	unsigned int	i;

	i = 1;
	if (!(fmt->flags & FLAGS_LEFT))
	{
		while (fmt->flags & FLAGS_ZEROPAD && i++ < fmt->width)
			out_char('0', fmt->idx++);
		while (i++ < fmt->width)
			out_char(' ', fmt->idx++);
	}
	out_char(**format, fmt->idx++);
	if (fmt->flags & FLAGS_LEFT)
		while (i++ < fmt->width)
			out_char(' ', fmt->idx++);
	(*format)++;
}

void	ft_type_else_format(const char **format, va_list va, t_format *fmt)
{
	while (**format)
	{
		if (**format == '0' || **format == '-')
		{
			ft_flags(format, fmt);
			(*format)--;
		}
		else if (is_digit(**format))
		{
			fmt->width = ft_atoi_pf(format);
			(*format)--;
		}
		else if (**format == '*')
		{
			ft_width(format, va, fmt);
			(*format)--;
		}
		else if (**format == '%')
		{
			ft_type_else_out_char(format, fmt);
			break ;
		}
		(*format)++;
	}
}
