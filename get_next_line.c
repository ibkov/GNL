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

int get_next_line(int fd, char **line)
{
	int BUFFER_SIZE = 1;
	char buffer[BUFFER_SIZE];
	char *str;
	int read_number;
	char *p_n;
	int flag = 1;

	ft_bzero(line, 1);
	str = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (flag && (read_number = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[read_number] = '\0';
		if ((p_n = ft_strchr(str, '\n')))
		{
			*p_n = '\0';
			flag = 0;
		}
		str = ft_strjoin(str, buffer);
	}
	return (0);
}