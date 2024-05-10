NAME = miniRT

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Include directories
INCDIR = ./includes

# Library paths
LIBFT_DIR = ./lib/libft
MINILIBX_DIR = ./lib/minilibx_opengl

# Source files
SRC = srcs/main.c \
	  srcs/init_data.c \
	  srcs/wait_input.c \
	  srcs/esc_close.c \
	  srcs/exit_on_close.c \

SRC += srcs/parser/parser.c \

SRC += srcs/ray/ray_math.c \

SRC += srcs/mlx/my_mlx_pixel_put.c \
	srcs/mlx/put_pixel.c \

# Objects directory
OBJDIR = ./objs
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a
LIBS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit

# Compilation rules
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I$(INCDIR) $(LIBS) -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
