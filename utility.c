/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:21:41 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/18 13:23:46 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

int	is_digit(char c)
{
	return ((c >= '0') && (c <= '9'));
}

size_t	ft_strnlen(const char *str, int maxsize)
{
	const char	*s;

	s = str;
	while (*s && maxsize--)
		s++;
	return ((size_t)(s - str));
}

size_t	ft_atoi_pf(const char **str)
{
	size_t	i;

	i = 0;
	while (is_digit(**str))
		i = i * 10 + (unsigned int)(*((*str)++) - '0');
	return (i);
}
