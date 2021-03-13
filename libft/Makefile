#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Updated: 2020/10/29 00:00:01 by sbrenton          #+#    #+#             *#
#*   Updated: 2020/11/09 00:00:01 by sbrenton         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror
HEADER = $(NAME:.a=.h)

SRS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
	ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c

OBJ = $(SRS:.c=.o)

SRS_BONUS = get_next_line.c
OBJ_BONUS = $(SRS_BONUS:.c=.o)

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus:  $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
