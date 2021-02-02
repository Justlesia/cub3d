cmake_minimum_required(VERSION 3.17)
project(cum3d C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")

add_executable(cum3d main.c parcer.c libft/ft_lstsize.c libft/libft.h libft/ft_strtrim.c libft/ft_strdup.c libft/ft_calloc.c libft/ft_bzero.c  libft/ft_atoi.c  libft/get_next_line.c  libft/ft_itoa.c  libft/ft_lstadd_back.c  libft/ft_lstnew.c  libft/ft_strlen.c)



