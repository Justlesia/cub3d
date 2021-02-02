NAME = test
MLXDIR = mlx_mms
MLXLIB = libmlx.dylib

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = yellow-square.c
OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLXDIR)
	@cp $(MLXDIR)/$(MLXLIB) ./
	@$(CC) -g $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
