/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:18:23 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/17 19:00:12 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(const char **format, t_format *fmt)
{
	fmt->flags = 0;
	while (1)
	{
		if (**format == '0')
				fmt->flags |= FLAGS_ZEROPAD;
		else if (**format == '-')
			fmt->flags = FLAGS_LEFT;
		else if (**format == '+')
			fmt->flags |= FLAGS_PLUS;
		else if (**format == ' ')
			fmt->flags |= FLAGS_SPACE;
		else if (**format == '#')
			fmt->flags |= FLAGS_HASH;
		else
			break ;
		(*format)++;
	}
	if (fmt->flags & FLAGS_LEFT)
		fmt->flags &= ~FLAGS_ZEROPAD;
}
