NAME := geometry_game
CC := cc
MLX = libmlx_Linux.a -lXext -lX11 -lm -lz
CFLAGS := -Werror -Wextra -Wall -Iinc

SRC = geometry.c \
	  draw_hori_lines.c \
	  draw_vert_lines.c \
	  draw_line.c		\
	  draw_grid.c		\
	  fill_square.c		\
	  my_mlx_pixel_put.c 

OBJ = $(addprefix obj/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ $(MLX) -o $(NAME)

obj/%.o : %.c 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all
