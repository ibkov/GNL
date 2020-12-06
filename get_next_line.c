/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:53:28 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/11 17:53:32 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_check_last(char *last, char **line)
{
	char *p_n;

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
		*line = ft_calloc(1,1);
	return (p_n);
}

int get_next_line(int fd, char **line) {
	char buffer[BUFFER_SIZE + 1];
	int read_number;
	char *p_n;
	static char *last;
	char *temp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	p_n = ft_check_last(last, line);
	while (!p_n && (read_number = read(fd, buffer, BUFFER_SIZE))) {
		buffer[read_number] = '\0';
		if ((p_n = ft_strchr(buffer, '\n'))) {
			*p_n = '\0';
			p_n++;
			free(last);
			last = ft_strdup(p_n);
		}
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		free(temp);
	}
	if (p_n)
		return (1);
	return (0);
}
