/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:21:02 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/12 10:00:39 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_out_buf(t_format *fmt)
{
	size_t	i;

	i = 0;
	while (i < fmt->buf_len)
	{
		write(STDOUT_FILENO, &fmt->buf[i], 1);
		fmt->idx++;
		i++;
	}
	fmt->buf_len = 0;
}

void	ft_out_char(char c, t_format *fmt)
{
	if (fmt->idx >= INT_MAX)
	{
		fmt->error = TRUE;
		return ;
	}
	if (fmt->buf_len)
		ft_out_buf(fmt);
	write(STDOUT_FILENO, &c, 1);
	fmt->idx++;
}

void	ft_out_rev(const char *buf, size_t len, t_format *fmt)
{
	size_t	i;
	size_t	start_idx;

	i = len;
	start_idx = fmt->idx;
	if (!(fmt->flags & FLAGS_LEFT) && !(fmt->flags & FLAGS_ZEROPAD))
		while (i++ < fmt->width)
			ft_out_char(' ', fmt);
	while (len)
		ft_out_char(buf[--len], fmt);
	if (fmt->flags & FLAGS_LEFT)
		while (fmt->idx - start_idx < fmt->width)
			ft_out_char(' ', fmt);
}

void	ft_type_else_out_char(const char **format, t_format *fmt)
{
	size_t	i;

	i = 1;
	if (!(fmt->flags & FLAGS_LEFT))
	{
		while (fmt->flags & FLAGS_ZEROPAD && i++ < fmt->width)
			ft_out_char('0', fmt);
		while (i++ < fmt->width)
			ft_out_char(' ', fmt);
	}
	ft_out_char(**format, fmt);
	if (fmt->flags & FLAGS_LEFT)
		while (i++ < fmt->width)
			ft_out_char(' ', fmt);
	(*format)++;
}
