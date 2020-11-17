cmake_minimum_required(VERSION 3.17)
project(GNL C)

set(CMAKE_C_STANDARD 99)

add_executable(GNL main.c get_next_line.c get_next_line.h get_next_line_utils.c libft/libft.h libft/ft_putstr_fd.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strchr.c libft/ft_strjoin.c libft/ft_bzero.c)