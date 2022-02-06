/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:43:55 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/12 10:51:58 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef enum e_bool
{
	FALSE,
	TRUE,
}			t_bool;

typedef enum e_flags
{
	FLAGS_ZEROPAD	=	(1 << 0),
	FLAGS_LEFT		=	(1 << 1),
	FLAGS_PLUS		=	(1 << 2),
	FLAGS_SPACE		=	(1 << 3),
	FLAGS_HASH		=	(1 << 4),
	FLAGS_UPPERCASE	=	(1 << 5),
	FLAGS_PRECISION	=	(1 << 6),
	FLAGS_PTR		=	(1 << 7),
}			t_flags;

typedef struct s_format
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	base;
	size_t			idx;
	size_t			buf_len;
	char			*buf;
	int				negative;
	int				error;
}			t_format;

/*
** ft_printf.c 
*/
int		ft_printf(const char *format, ...);

/*
** ft_flags.c 
*/
void	ft_flags(const char **format, t_format *fmt);
void	ft_width(const char **format, t_format *fmt);
void	ft_precision(const char **format, t_format *fmt);

/*
** ft_type.c 
*/
void	ft_type(const char **format, va_list va, t_format *fmt);

/*
** ft_type2.c 
*/
void	ft_type_char(const char **format, va_list va, t_format *fmt);
void	ft_type_str(const char **format, va_list va, t_format *fmt);
void	ft_type_ptr(const char **format, va_list va, t_format *fmt);
void	ft_type_else(const char **format, t_format *fmt);

/*
** ft_forming.c 
*/
void	ft_forming(unsigned long value, t_format *fmt, int is_uint);

/*
** ft_value_len.c 
*/
size_t	ft_value_len(size_t len, t_format *fmt);

/*
** ft_out_char.c 
*/
void	ft_out_buf(t_format *fmt);
void	ft_out_char(char c, t_format *fmt);
void	ft_out_rev(const char *buf, size_t len, t_format *fmt);
void	ft_type_else_out_char(const char **format, t_format *fmt);

/*
** util_libft.c 
*/
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
char	*ft_strdup(const char *s1);

/*
** util.c 
*/
int		ft_error_check(const char *s, t_format *fmt);
int		ft_isdigit(char c);
int		ft_parse_length(const char **format, t_format *fmt, int is_width);
size_t	ft_strnlen(const char *value, t_format *fmt);

#endif
