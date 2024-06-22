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
	  srcs/print_struct.c \

SRC += srcs/event/wait_input.c \
	   srcs/event/esc_close.c \
	   srcs/event/exit_on_close.c \

SRC += srcs/parser/check_file_extension.c \
	   srcs/parser/parse_file.c \
	   srcs/parser/parse_line.c \
	   srcs/parser/parse_ambient_light.c \
	   srcs/parser/parse_camera.c \
	   srcs/parser/parse_light.c \
	   srcs/parser/parse_sphere.c \
	   srcs/parser/parse_plane.c \
	   srcs/parser/parse_cylinder.c \
	   srcs/parser/is_out_of_range_int.c \
	   srcs/parser/is_out_of_range_double.c \
	   srcs/parser/is_rgb_out_of_range.c \
	   srcs/parser/is_vec3_out_of_range.c \
	   srcs/parser/parse_rectangle.c \

SRC += srcs/ray/ray_math.c \
	   srcs/ray/ray_math2.c \
	   srcs/ray/ray_math3.c \
	   srcs/ray/hittable_list.c \
	   srcs/ray/hittable_list2.c \
	   srcs/ray/sphere.c \
	   srcs/ray/random.c \
	   srcs/ray/progress.c \
	   srcs/ray/lambertian.c \
	   srcs/ray/metal.c \
	   srcs/ray/dielectric.c \
	   srcs/ray/camera.c \
	   srcs/ray/moving_sphere.c \
	   srcs/ray/rectangle.c \
	   srcs/ray/light.c \
	   srcs/ray/cylinder.c \
	   srcs/ray/cylinder2.c \
	   srcs/ray/ambient.c \
	   srcs/ray/plane.c \
	   srcs/ray/render.c \
	   srcs/ray/ray_color.c \

SRC += srcs/mlx/my_mlx_pixel_put.c \

SRC += srcs/error/exit_with_error.c \

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
