NAME = cub3D
CC  = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

SRC = src/main.c src/init_all.c src/init_map_utils.c src/init_map.c src/map_name_check.c src/utils.c \
		src/convert.c src/init_player.c src/map_surrounded.c src/map_check.c src/map_check_utils.c \
		src/move.c src/calculate.c src/raycasting.c

OBJS_DIR := objs/

OBJS := ./objs/main.o \
		./objs/init_all.o \
		./objs/init_map_utils.o \
		./objs/init_map.o \
		./objs/map_name_check.o \
		./objs/utils.o \
		./objs/convert.o \
		./objs/init_player.o \
		./objs/map_surrounded.o \
		./objs/map_check.o \
		./objs/map_check_utils.o \
		./objs/move.o \
		./objs/calculate.o \
		./objs/raycasting.o \

LIBFT_DIR := libft

MINILIBX_DIR := mlx

all: $(NAME)


$(NAME): $(OBJS_DIR) $(OBJS) 
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(MINILIBX_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -framework OpenGL  -framework AppKit -Lmlx -lmlx -g $(OBJS) -o $(NAME) 
	
$(OBJS_DIR)%.o: src/%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)


clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINILIBX_DIR)
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus
