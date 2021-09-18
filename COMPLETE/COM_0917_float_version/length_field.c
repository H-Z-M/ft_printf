/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:19:42 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/17 13:49:20 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lenght2(const char **format, t_format *fmt)
{
	if (**format == 't')
	{
		if (sizeof(ptrdiff_t) == sizeof(long))
			fmt->flags |= FLAGS_LONG;
		else
			fmt->flags |= FLAGS_LONG_LONG;
	}
	else if (**format == 'j')
	{
		if (sizeof(intmax_t) == sizeof(long))
			fmt->flags |= FLAGS_LONG;
		else
			fmt->flags |= FLAGS_LONG_LONG;
	}
	else if (**format == 'z')
	{
		if (sizeof(size_t) == sizeof(long))
			fmt->flags |= FLAGS_LONG;
		else
			fmt->flags |= FLAGS_LONG_LONG;
	}
	(*format)++;
}

void	ft_length(const char **format, t_format *fmt)
{
	if (**format == 'l')
	{
		fmt->qualifier = **format;
		fmt->flags |= FLAGS_LONG;
		(*format)++;
		if (**format == 'l')
		{
			fmt->flags |= FLAGS_LONG_LONG;
			(*format)++;
		}
	}
	else if (**format == 'h')
	{
		fmt->qualifier = **format;
		fmt->flags |= FLAGS_SHORT;
		(*format)++;
		if (**format == 'h')
		{
			fmt->flags |= FLAGS_CHAR;
			(*format)++;
		}
	}
	else if (**format == 't' || **format == 'j' || **format == 'z')
		ft_lenght2(format, fmt);
}
