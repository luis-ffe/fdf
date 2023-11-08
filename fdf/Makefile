NAME = fdf

SRCS_LIST = fdf.c

SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LIST:.c=.o))

LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

LIBFTPRINTF_DIR = libft/ft_printf
LIBFTPRINTF = $(addprefix $(LIBFTPRINTF_DIR), libftprintf.a)

GET_NEXT_DIR = libft/get_next_line
GET_NEXT = $(addprefix $(GET_NEXT_DIR), get_next_line.a)

LIBMLX_DIR = minilibx/
LIBMLX = $(addprefix $(LIBMLX_DIR), libmlx.a)

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFLAGS = -L$(GET_NEXT) -L$(LIBFTPRINTF) -L$(LIBFT_DIR) -lft -L$(LIBMLX_DIR) -lmlx -lX11 -lXext -lm
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

$(GET_NEXT):
	make -C $(GET_NEXT_DIR)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

clean:
	$(RM) $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBFTPRINTF_DIR)
	make clean -C $(GET_NEXT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBFTPRINTF_DIR)
	make fclean -C $(GET_NEXT_DIR)
	make clean -C $(LIBMLX_DIR)

re: fclean all