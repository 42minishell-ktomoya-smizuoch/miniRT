NAME = miniRT

CC = gcc
CFLAGS = -O2 -Wall -Wextra -Werror

# Include directories
INCDIR = ./includes

# Library paths
LIBFT_DIR = ./lib/libft
MINILIBX_DIR = ./lib/minilibx_opengl

# Source files
SRC = srcs/main.c \
	  srcs/init_data.c \

SRC += srcs/checker/check_file_extension.c \

SRC += srcs/event/wait_input.c \
	   srcs/event/esc_close.c \
	   srcs/event/exit_on_close.c \

SRC += srcs/parser/parser.c \

SRC += srcs/ray/ray_math.c \
	   srcs/ray/ray_math2.c \
	   srcs/ray/hittable_list.c \
	   srcs/ray/sphere.c \
	   srcs/ray/random.c \
	   srcs/ray/progress.c \
	   srcs/ray/metal.c \
	   srcs/ray/dielectric.c \
	   srcs/ray/camera.c \

SRC += srcs/mlx/my_mlx_pixel_put.c \

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
