/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:21:13 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/14 09:21:14 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision(const char **format, va_list va, t_format *fmt)
{
	int	prec;

	fmt->precision = 0;
	if (**format == '.')
	{
		fmt->flags |= FLAGS_PRECISION;
		(*format)++;
		if (is_digit(**format))
			fmt->precision = ft_atoi_pf(format);
		else if (**format == '*')
		{
			prec = va_arg(va, int);
			if (prec >= 0)
				fmt->precision = (unsigned int)prec;
			else
				fmt->flags &= ~FLAGS_PRECISION;
			(*format)++;
		}
	}
}
