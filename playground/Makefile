NAME = playground

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Include directories
INCDIR = ../includes

# Library paths
LIBFT_DIR = ../lib/libft
MINILIBX_DIR = ../lib/minilibx_opengl

# Source files
SRC = mlx_init.c \

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
