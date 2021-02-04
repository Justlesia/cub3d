NAME = test
MLXDIR = mlx_mms
MLXLIB = libmlx.dylib

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c parcer.c libft/ft_lstsize.c libft/ft_strtrim.c libft/ft_strdup.c libft/ft_calloc.c libft/ft_bzero.c  libft/ft_atoi.c  libft/get_next_line.c  libft/ft_itoa.c  libft/ft_lstadd_back.c  libft/ft_lstnew.c  libft/ft_strlen.c
OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLXDIR)
	@cp $(MLXDIR)/$(MLXLIB) ./
	@$(CC) -g $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@make clean -C $(MLXDIR)
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

debag:
	@$(CC) -g $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)