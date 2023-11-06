CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx_macos
MLX = $(MLX_DIR)/libmlx.a
MLX_HEADERS = -I $(MLX_DIR)
NAME = fdf
SRC = window.c
OBJ = $(SRC:.c=.o)
KIT = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(KIT)

$(MLX):
	make re -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_HEADERS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all