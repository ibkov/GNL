/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:53:28 by burswyck          #+#    #+#             */
/*   Updated: 2020/12/12 14:15:59 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			if (!(*line = ft_strdup(last)))
				return (0);
			p_n++;
			ft_strcpy(last, p_n);
		}
		else
		{
			if (!(*line = ft_strdup(last)))
				return (0);
			*last = '\0';
		}
	else
		if (!(ft_calloc(line)))
			return (0);
	return (p_n);
}

int	free_join_line(char **line, char *buffer)
{
	char	*temp;

	temp = *line;
	if (!(*line = ft_strjoin(*line, buffer)))
		return (0);
	free(temp);
	return (1);
}

char *free_mem(char *p_n, char *last)
{
	char *temp;

	*p_n = '\0';
	temp = last;
	if (!(last = ft_strdup(++p_n)))
		return (0);
	free(temp);
	return (last);
}

int		get_next_line(int fd, char **line)
{
	char			buffer[((BUFFER_SIZE) < 1) ? (1) : (BUFFER_SIZE + 1)];
	int				rn;
	char			*p_n;
	static char		*last;

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
			last = free_mem(p_n, last);
		}
		if (!(free_join_line(line, buffer)))
			return (-1);
	}
	return (p_n) ? 1 : 0;
}
