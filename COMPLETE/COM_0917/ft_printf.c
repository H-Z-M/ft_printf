/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:03:20 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/17 12:37:24 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "leakdetect.h"
#define malloc(s) leak_detect_malloc(s, __FILE__, __LINE__)
#define free leak_detect_free

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

int	ft_printf(const char *format, ...)
{
	leak_detect_init();
	va_list		va;
	size_t		idx;
	t_format	*fmt;

	fmt = (t_format *)malloc(sizeof(t_format));
	fmt->idx = 0;
	va_start(va, format);
	ft_printf_internal(format, va, fmt);
	va_end(va);
	idx = fmt->idx;
	free(fmt);
	leak_detect_check();
	return (idx);
}
