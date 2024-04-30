/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:35:43 by smizuoch          #+#    #+#             */
/*   Updated: 2024/04/27 14:07:34 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line/get_next_line.h"
# include "../lib/libft/get_next_line/get_next_line_bonus.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 1024

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
