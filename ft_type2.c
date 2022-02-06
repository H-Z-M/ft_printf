/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:15:17 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/11 21:24:11 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_char(const char **format, va_list va, t_format *fmt)
{
	char	value;
	size_t	i;

	i = 1;
	if (!(fmt->flags & FLAGS_LEFT))
		while (i++ < fmt->width)
			ft_out_char(' ', fmt);
	value = (char)va_arg(va, int);
	ft_out_char(value, fmt);
	if (fmt->flags & FLAGS_LEFT)
		while (i++ < fmt->width)
			ft_out_char(' ', fmt);
	(*format)++;
}

void	ft_type_str(const char **format, va_list va, t_format *fmt)
{
	char	*value;
	size_t	i;

	value = va_arg(va, char *);
	if (value == NULL)
		value = "(null)";
	i = ft_strnlen(value, fmt);
	if (!(fmt->flags & FLAGS_LEFT))
		while (i++ < fmt->width)
			ft_out_char(' ', fmt);
	while (*value && (!(fmt->flags & FLAGS_PRECISION) || fmt->precision--))
		ft_out_char(*(value++), fmt);
	if (fmt->flags & FLAGS_LEFT)
		while (i++ < fmt->width)
			ft_out_char(' ', fmt);
	(*format)++;
}

void	ft_type_ptr(const char **format, va_list va, t_format *fmt)
{
	unsigned long	value;
	unsigned long	tmp;
	size_t			i;

	value = (unsigned long)va_arg(va, void *);
	fmt->flags |= (FLAGS_HASH | FLAGS_PTR);
	fmt->negative = FALSE;
	fmt->base = 16;
	tmp = value;
	i = 0;
	while (tmp)
	{
		tmp /= fmt->base;
		i++;
	}
	if (i == fmt->width || (!value && fmt->width == 1))
		fmt->width = 0;
	ft_forming(value, fmt, FALSE);
	(*format)++;
}

void	ft_type_else(const char **format, t_format *fmt)
{
	while (**format)
	{
		if (**format == '0' || **format == '-')
		{
			ft_flags(format, fmt);
			(*format)--;
		}
		else if (ft_isdigit(**format))
		{
			fmt->width = ft_parse_length(format, fmt, TRUE);
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
