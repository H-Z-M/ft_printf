/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:15:08 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/14 09:15:09 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			ft_width(&format, va, fmt);
			ft_precision(&format, va, fmt);
			ft_length(&format, fmt);
			ft_type(&format, va, fmt);
		}
	}
}
