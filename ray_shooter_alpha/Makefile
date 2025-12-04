NAME := ray_shooter
CC := cc
MLX = libmlx_Linux.a -lXext -lX11 -lm -lz
CFLAGS := -Werror -Wextra -Wall -Iinc -g

SRC = \
	  draw_line.c \
	  render_window.c \
	  init_tex.c \
	  turn_player.c \
	  print_user_info.c \
	  init_user.c \
	  out_of_bounds.c \
	  fill_img_with.c \
	  calc_ray_length.c \
	  wolfenstein_tex.c \
	  wolfenstein.c \
	  fill_square.c \
	  init_data.c \
	  init_grid.c \
	  main.c \
	  my_mlx_create_image.c \
	  mouse_click.c \
	  keyboard.c \
	  wall_collision.c \
	  move_player.c \
	  shoot_ray.c \
	  my_mlx_pixel_put.c \
	  square_on_click.c 

OBJ = $(addprefix obj/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ $(MLX) -o $(NAME)

obj/%.o : src/%.c 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all
