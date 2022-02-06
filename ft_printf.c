/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:03:20 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/12 10:22:44 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_init(void)
{
	t_format	*fmt;

	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (NULL);
	fmt->idx = 0;
	fmt->buf = NULL;
	fmt->buf_len = 0;
	fmt->error = FALSE;
	return (fmt);
}

void	ft_join_buf(const char *format, t_format *fmt)
{
	char	*tmp;

	if (fmt->buf_len)
	{
		tmp = ft_strdup(fmt->buf);
		if (ft_error_check(tmp, fmt))
			return ;
		free(fmt->buf);
		fmt->buf = ft_strnjoin(tmp, format, 1);
		free(tmp);
		if (ft_error_check(fmt->buf, fmt))
			return ;
		fmt->buf_len++;
	}
	else
	{
		if (fmt->buf)
			free(fmt->buf);
		fmt->buf = malloc(2);
		fmt->buf[0] = *format;
		fmt->buf[1] = '\0';
		fmt->buf_len++;
	}
}

void	ft_printf_internal(const char *format, va_list va, t_format *fmt)
{
	while (*format && !fmt->error)
	{
		if (*format != '%' && !fmt->error)
		{
			ft_join_buf(format, fmt);
			format++;
			continue ;
		}
		else
			format++;
		if (*format == '%' && !fmt->error)
		{
			ft_out_char('%', fmt);
			format++;
		}
		else if (!fmt->error)
		{
			ft_flags(&format, fmt);
			ft_width(&format, fmt);
			ft_precision(&format, fmt);
			ft_type(&format, va, fmt);
		}
	}
}

int	ft_printf(const char *format, ...)
{
	int			idx;
	va_list		va;
	t_format	*fmt;

	fmt = ft_init();
	if (!fmt)
		return (-1);
	va_start(va, format);
	ft_printf_internal(format, va, fmt);
	va_end(va);
	if (fmt->error)
		fmt->idx = -1;
	else if (fmt->buf_len)
		ft_out_buf(fmt);
	idx = fmt->idx;
	free(fmt->buf);
	free(fmt);
	return (idx);
}
