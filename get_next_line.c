/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:53:28 by burswyck          #+#    #+#             */
/*   Updated: 2020/12/10 20:37:22 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_calloc(char **line)
{
	if (!(*line = (char *)malloc(sizeof(char) * 1)))
		return (0);
	*line[0] = '\0';
	return (1);
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
		ft_calloc(line);
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
			temp = last;
			last = ft_strdup(++p_n);
			free(temp);
		}
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		free(temp);
	}
	return (p_n) ? 1 : 0;
}
