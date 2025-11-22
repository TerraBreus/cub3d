NAME := ray_shooter
CC := cc
MLX = libmlx_Linux.a -lXext -lX11 -lm -lz
CFLAGS := -Werror -Wextra -Wall -Iinc -g

SRC = main.c 

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
