/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:01:24 by ailopez-          #+#    #+#             */
/*   Updated: 2024/01/15 00:39:48 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void	control_keys3(int key, t_fdf *fdf)
{
	if (key == KEY_B)
	{
		if (fdf->keys.b_keyctrl)
			fdf->map.brange -= 0.0001;
		else
			fdf->map.brange += 0.0001;
	}
	if (key == KEY_SUM || key == KEY_SUM2)
	{
		if (fdf->keys.b_keyctrl)
			fdf->map.scale = fdf->map.scale * 1.5;
		if (fdf->map.zdivisor > 1)
			fdf->map.zdivisor -= 10;
	}
	if (key == KEY_RES || key == KEY_RES2)
	{
		if (fdf->keys.b_keyctrl)
			fdf->map.scale = fdf->map.scale / 1.5;
		fdf->map.zdivisor += 10;
	}
	if (key == KEY_I)
	{
		isometric(&fdf->map);
		draw_map(fdf, FIT);
	}			
}

void	control_keys2(int key, t_fdf *fdf)
{
	if (key == KEY_D)
		fdf->map.b_dots = !fdf->map.b_dots;
	if (key == KEY_L)
		fdf->map.b_lines = !fdf->map.b_lines;
	if (key == KEY_X)
		fdf->map.b_pluslines = !fdf->map.b_pluslines;
	if (key == KEY_G)
		fdf->map.sphere = !fdf->map.sphere;
	if (key == KEY_S)
		fdf->map.b_stars = !fdf->map.b_stars;
	if (key == KEY_H)
		fdf->map.b_shadow = !fdf->map.b_shadow;
	if (key == KEY_F)
		draw_map(fdf, FIT);
	if (key == KEY_CMD)
		fdf->keys.b_keyctrl = 1;
}

void	control_keys1(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
		terminate_program(fdf);
	if (key == KEY_R)
	{
		map_ini(&fdf->map, 0);
		fdf->map.proportion = \
		fdf->map.limits.axis[Z] / fdf->map.limits.axis[X];
		if (fdf->map.proportion > 0.5)
			fdf->map.zdivisor = fdf->map.proportion * 100;
		colorize(&fdf->map);
		draw_map(fdf, FIT);
	}	
	if (key == KEY_C)
	{
		fdf->map.source.axis[X] = ((WINX - MENU_WIDTH) / 2) + 	MENU_WIDTH;
		fdf->map.source.axis[Y] = WINY / 2;
	}
	if (key == KEY_P)
	{
		parallel(&fdf->map);
		draw_map(fdf, FIT);
	}			
}

int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	angle_control(key, fdf);
	control_keys1(key, fdf);
	control_keys2(key, fdf);
	control_keys3(key, fdf);
	if (key >= KEY_1 && key <= KEY_4)
		control_colorscheme(key, &fdf->map);
	draw_map(fdf, FREE);
	return (0);
}


int	key_release(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == KEY_CMD)
		fdf->keys.b_keyctrl = 0;
	return (0);
}
