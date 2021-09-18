/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:22:22 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/14 09:22:23 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(const char **format, va_list va, t_format *fmt)
{
	int	w;

	fmt->width = 0;
	if (is_digit(**format))
		fmt->width = ft_atoi_pf(format);
	else if (**format == '*')
	{
		w = va_arg(va, int);
		if (w < 0)
		{
			fmt->flags |= (FLAGS_LEFT | FLAGS_MINUS_WIDTH);
			fmt->width = (unsigned int)(-w);
		}
		else
			fmt->width = (unsigned int)w;
		(*format)++;
	}
}
