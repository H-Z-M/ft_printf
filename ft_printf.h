/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:43:55 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/18 13:24:12 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define TRUE	1
# define FALSE	0

typedef enum e_flags
{
	FLAGS_ZEROPAD =			(1 << 0),
	FLAGS_LEFT =			(1 << 1),
	FLAGS_PLUS =			(1 << 2),
	FLAGS_SPACE =			(1 << 3),
	FLAGS_HASH =			(1 << 4),
	FLAGS_UPPERCASE =		(1 << 5),
	FLAGS_PRECISION =		(1 << 6),
	FLAGS_PTR =				(1 << 7),
}			t_flags;

typedef struct s_format
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	base;
	size_t			idx;
	int				negative;
}			t_format;

/*
** ft_printf.c 
*/
int		ft_printf(const char *format, ...);
void	ft_flags(const char **format, t_format *fmt);
void	ft_precision(const char **format, t_format *fmt);

/*
** type_field.c 
*/
void	ft_type(const char **format, va_list va, t_format *fmt);

/*
** type_field2.c 
*/
void	ft_type_char(const char **format, va_list va, t_format *fmt);
void	ft_type_str(const char **format, va_list va, t_format *fmt);
void	ft_type_ptr(const char **format, va_list va, t_format *fmt);

/*
** ntoa_uint.c 
*/
size_t	ntoa_uint(size_t idx, unsigned int value, t_format *fmt);

/*
** ntoa_ulong.c 
*/
size_t	ntoa_ulong(size_t idx, unsigned long value, t_format *fmt);

/*
** ntoa_format.c 
*/
size_t	ntoa_format(char *buf, size_t idx, size_t len, t_format *fmt);
size_t	ntoa_format_len(size_t len, t_format *fmt);
size_t	ntoa_format_hash_len(size_t len, t_format *fmt);

/*
** out_char.c 
*/
void	out_char(char character, size_t idx);
void	ft_type_else_format(const char **format, t_format *fmt);
size_t	out_rev(size_t idx, const char *buf, size_t len, t_format *fmt);

/*
** utility.c 
*/
int		is_digit(char ch);
void	ft_putchar(char c);
size_t	ft_atoi_pf(const char **str);
size_t	ft_strnlen(const char *str, int maxsize);

#endif
