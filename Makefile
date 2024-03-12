NAME = cub3D

SRC = src/main.c src/init_all.c src/init_map_utils.c src/init_map.c src/map_name_check.c src/utils.c \
		src/convert.c src/init_player.c src/map_surrounded.c src/map_check.c src/map_check_utils.c \
		src/move.c src/calculate.c src/raycasting.c src/utils2.c

FLAGS = gcc -Wall -Wextra -Werror -g

RM = rm -f

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	make -C mlx
	$(FLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	make fclean -C libft
	make clean -C mlx
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
