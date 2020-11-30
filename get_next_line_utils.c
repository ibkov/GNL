/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:54:15 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/11 17:54:17 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strdup(const char *s1)
{
	char    *str;
	char    *new_str;

	if (!(str = malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (0);
	new_str = str;
	while (*s1)
		*str++ = *s1++;
	*str = '\0';
	return (new_str);
}


char    *ft_strjoin(char const *s1, char const *s2)
{
	char    *str_joined;
	int        len_all_str;

	if (!s1 || !s2)
		return (0);
	len_all_str = ft_strlen(s1) + ft_strlen(s2);
	if (!(str_joined = malloc(sizeof(str_joined) * (len_all_str) + 1)))
		return (0);
	while (*s1)
		*str_joined++ = *s1++;
	while (*s2)
		*str_joined++ = *s2++;
	*str_joined = '\0';
	return (str_joined - len_all_str);
}

char    *ft_strchr(const char *string, int symbol)
{
	while (*string != symbol && *string)
	{
		string++;
	}
	if (symbol == '\0')
		return ((char*)string);
	if (*string == '\0')
		return (0);
	return ((char*)string);
}


int    ft_strlen(const char *str)
{
	int        i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}


void    ft_bzero(void *s, size_t n)
{
	char *str;

	str = (char*)s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}


void    *ft_calloc(size_t count, size_t size)
{
	char    *s;

	if (!(s = (char *)malloc(count * size)))
		return (0);
	ft_bzero(s, count * size);
	return (s);
}

size_t		ft_strlcpy(char *restrict dst,\
const char *restrict src, size_t dstsize)
{
	size_t	len;

	if (!dst && !src)
		return (0);
	len = (size_t)ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (*src && dstsize > 1)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	return (len);
}