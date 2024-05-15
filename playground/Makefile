NAME = playground.out

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g

# Include directories
INCDIR = ../includes

# Library paths
LIBFT_DIR = ../lib/libft
MINILIBX_DIR = ../lib/minilibx_opengl

# Source files
SRC = parser.c \
#	main.c \
#	mlx_init.c \
#	write_pixel.c \

# Objects directory
OBJDIR = ./objs
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a
LIBS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -I$(MINILIBX_DIR) -framework OpenGL -framework AppKit

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

ifeq ($(MAKECMDGOALS), debug)
CFLAGS += $(DEBUGFLAGS)
endif

debug: re

.PHONY: all clean fclean re
