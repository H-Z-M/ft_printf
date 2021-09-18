/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:03:20 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/09 02:32:47 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* #include "/home/sss/UTIL/leakdetect.h" */
/* #define malloc(s) leak_detect_malloc(s, __FILE__, __LINE__) */
/* #define free leak_detect_free */

int	ft_printf(const char *format, ...)
{
	/* leak_detect_init(); */
	va_list		va;
	size_t		idx;
	t_format	*fmt;

	fmt = (t_format *)malloc(sizeof(t_format));
	fmt->idx = 0;
	fmt->maxlen = (size_t)(-1);
	va_start(va, format);
	ft_printf_internal(format, va, fmt);
	va_end(va);
	idx = fmt->idx;
	free(fmt);
	/* leak_detect_check(); */
	return (idx);
}
