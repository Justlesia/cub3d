NAME = cub3D

MLXDIR = mlx_mms
MLXLIB = libmlx.dylib

DIR = libft
LIB = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/parcer_params.c src/parcer_outsource.c src/parcer_map.c src/ray_what_pic.c src/parcer_params_units.c src/parcer_params_init.c src/functions.c src/ray_fish.c src/ray_draw.c src/ray_draw_bf.c src/pics.c src/error.c src/save.c src/action.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@make -C $(MLXDIR)
	@cp $(MLXDIR)/$(MLXLIB) ./
	@make -C $(DIR)
	@cp $(DIR)/$(LIB) ./
	$(CC) -g $(OBJ) -L. -O3 -lmlx $(LIB) -framework OpenGL -framework AppKit -o  $(NAME)

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -O3 -c $< -o $@

clean:
	@make clean -C $(MLXDIR)
	@make clean -C $(DIR)
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIB) $(DIR)/$(LIB)
	@/bin/rm -f $(MLXLIB) $(MLXDIR)/$(MLXLIB)
	@/bin/rm -f image.bmp

re: fclean all

bonus: all