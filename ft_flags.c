/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:26:34 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/12 10:48:10 by sudatsu          ###   ########.fr       */
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
		if (ft_isdigit(**format))
			fmt->precision = ft_parse_length(format, fmt, FALSE);
	}
}

void	ft_width(const char **format, t_format *fmt)
{
	fmt->width = 0;
	if (ft_isdigit(**format))
		fmt->width = ft_parse_length(format, fmt, TRUE);
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
