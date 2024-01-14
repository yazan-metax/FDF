/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:45:09 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/15 00:09:42 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void	angle(float *ang, float value)
{
	*ang += value;
	if (*ang < 0)
			*ang = 360 + *ang;
	if (*ang >= 360)
			*ang = *ang - 360;
}

void	angle_control(int key, t_fdf *fdf)
{
	int	ang;

	ang = 1;
	if (fdf->keys.b_keyctrl)
		ang = 90;
	if (key == KEY_DOWN)
		angle(&fdf->map.ang[X], ang);
	if (key == KEY_UP)
		angle(&fdf->map.ang[X], -ang);
	if (key == KEY_LEFT)
		angle(&fdf->map.ang[Y], ang);
	if (key == KEY_RIGHT)
		angle(&fdf->map.ang[Y], -ang);
	if (key == KEY_Q)
		angle(&fdf->map.ang[Z], ang);
	if (key == KEY_W)
		angle(&fdf->map.ang[Z], -ang);
}

int	terminate_program(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_destroy_window(fdf->win.mlx, fdf->win.win);
	free(fdf->map.points);
	exit(0);
}

void	terminate(char *s)
{
	 if (errno == 0)
		ft_putendl_fd(s,2);
	else
		perror(s);
	exit(EXIT_FAILURE); 
}

void	control_colorscheme(int key, t_map *map)
{
	map->colors.background = CARBON;
	map->colors.bottom = BLUE;
	map->colors.top = BRICK_RED;
	map->colors.ground = SAFFRON;
	if (key == KEY_1)
	{
		map->colors.bottom = WHITE;
		map->colors.top = WHITE;
		map->colors.ground = WHITE;
	}
	colorize(map);
}
