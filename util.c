/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:21:41 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/12 11:05:57 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_error_check(const char *s, t_format *fmt)
{
	if (!s)
	{
		fmt->error = TRUE;
		return (1);
	}
	return (0);
}

int	ft_isdigit(char c)
{
	return ((c >= '0') && (c <= '9'));
}

size_t	ft_strnlen(const char *value, t_format *fmt)
{
	const char	*s;
	size_t		maxsize;

	if (fmt->precision)
		maxsize = fmt->precision;
	else
		maxsize = INT_MAX;
	s = value;
	while (*s && maxsize--)
		s++;
	return (s - value);
}

int	ft_parse_length(const char **format, t_format *fmt, int is_width)
{
	long	i;

	i = 0;
	while (ft_isdigit(**format))
	{
		i *= 10;
		i += (long)(*((*format)++) - '0');
		if (fmt->idx + i >= INT_MAX && is_width)
			fmt->error = TRUE;
	}
	return (i);
}
