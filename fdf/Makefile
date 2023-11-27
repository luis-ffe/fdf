NAME = fdf

SRCS_LIST = main.c keys.c keys_2.c window.c get_data.c utilis.c init.c \
			img_pixel.c draw.c draw_utilis.c bresenham_algo.c 

SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LIST:.c=.o))

LIBFT_DIR = includes/libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

LIBMLX_DIR = includes/minilibx-linux/
LIBMLX = $(addprefix $(LIBMLX_DIR), libmlx.a)

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFLAGS = -L$(LIBFT_DIR) -lft -L$(LIBMLX_DIR) -lmlx -lX11 -lXext -lm
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

clean:
	$(RM) $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

re: fclean all