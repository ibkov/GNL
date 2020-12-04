/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:53:56 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/11 17:54:02 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_GET_NEXT_LINE_H
#define GNL_GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

int get_next_line(int fd, char **line);
char    *ft_strdup(const char *s1);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strchr(const char *string, int symbol);
int    ft_strlen(const char *str);
void    ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t count, size_t size);
void    ft_strcpy(char *restrict dst,\
const char *restrict src);

#endif //GNL_GET_NEXT_LINE_H
