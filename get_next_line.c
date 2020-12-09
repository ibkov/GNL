/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:53:28 by burswyck          #+#    #+#             */
/*   Updated: 2020/12/08 22:46:10 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	if (!(s = (char *)malloc(count * size)))
		return (0);
	ft_bzero(s, count * size);
	return (s);
}

void	ft_strcpy(char *restrict dst,\
const char *restrict src)
{
	if (!dst && !src)
		return ;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}

char	*ft_check_last(char *last, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (last)
		if ((p_n = ft_strchr(last, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(last);
			p_n++;
			ft_strcpy(last, p_n);
		}
		else
		{
			*line = ft_strdup(last);
			*last = '\0';
		}
	else
		*line = ft_calloc(1, 1);
	return (p_n);
}

int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	int				rn;
	char			*p_n;
	static char		*last;
	char			*temp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	p_n = ft_check_last(last, line);
	while (!p_n && (rn = read(fd, buffer, BUFFER_SIZE)))
	{
		if (rn == -1)
			return (-1);
		buffer[rn] = '\0';
		if ((p_n = ft_strchr(buffer, '\n')))
		{
			*p_n = '\0';
			p_n++;
			free(last);
			last = ft_strdup(p_n);
		}
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		free(temp);
	}
	return (p_n) ? 1 : 0;
}
