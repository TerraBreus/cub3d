NAME := geometry_game
CC := cc
MLX = libmlx_Linux.a -lXext -lX11 -lm -lz
CFLAGS := -Werror -Wextra -Wall -Iinc -g

SRC = main.c \
	  init_data.c		\
	  draw_line.c		\
	  draw_grid.c		\
	  fill_square.c		\
	  move_keyboard.c	\
	  square_on_click.c	\
	  move_mouse.c		\
	  draw_mouse.c		\
	  get_pixel_color.c	\
	  draw_line_between_points.c	\
	  my_mlx_create_image.c	\
	  merge_images_and_push_to_window.c \
	  draw_keyboard.c	\
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
