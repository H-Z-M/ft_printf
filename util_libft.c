/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 08:40:04 by sudatsu           #+#    #+#             */
/*   Updated: 2021/12/12 09:17:00 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = src;

	d = (unsigned char *)dst;
	if (!d && !s)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, len);
	return (copy);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*ptr;
	char	*top;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + n + 1);
	if (!ptr)
		return (NULL);
	top = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2 && n--)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (top);
}
