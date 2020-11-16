cmake_minimum_required(VERSION 3.17)
project(GNL C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUFFER_SIZE 10)
add_executable(GNL main.c get_next_line.c get_next_line.h get_next_line_utils.c libft/libft.h libft/ft_putstr_fd.c libft/ft_strdup.c libft/ft_strlen.c)