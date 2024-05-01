/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:35:43 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/01 11:25:32 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "../lib/minilibx_opengl/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line/get_next_line.h"
# include "../lib/libft/get_next_line/get_next_line_bonus.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define ERR_OPEN_FILE "Error: failed to open the file"
#define ERR_READ_FILE "Error: failed to read the file"
#define ERR_PARSE_FILE "Error: failed to parse the file"
#define ERR_MALLOC "Error: failed to allocate memory"
#define ERR_ARG "Error: invalid argument"
#define ERR_FILE_FORMAT "Error: invalid file format"

//構造体
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_camera
{
	t_vector	origin;
	t_vector	direction;
	double		fov;
}	t_camera;


#endif
