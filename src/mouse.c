/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:04:04 by ailopez-          #+#    #+#             */
/*   Updated: 2024/01/15 00:26:15 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == 1)
	{
		fdf->keys.b_mouse_l = 1;
		fdf->keys.last_click_l.axis[X] = x;
		fdf->keys.last_click_l.axis[Y] = y;
	}
	if (button == 2)
	{
		fdf->keys.b_mouse_r = 1;
		fdf->keys.last_click_r.axis[X] = x;
		fdf->keys.last_click_r.axis[Y] = y;
	}	
	if (button == 5)
	{
		if (fdf->map.scale > 2)
			fdf->map.scale = fdf->map.scale / 1.5;
	}
	if (button == 4)
		fdf->map.scale = fdf->map.scale * 1.5;
	draw_map(fdf, FREE);
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (x > WINX || x < 0 || y > WINY || y < 0)
		return (0);
	if (fdf->keys.b_mouse_l)
	{
		angle(&fdf->map.ang[X], (int)fdf->keys.last_click_l.axis[Y] - y);
		angle(&fdf->map.ang[Y], (int)fdf->keys.last_click_l.axis[X] - x);
		fdf->keys.last_click_l.axis[X] = x;
		fdf->keys.last_click_l.axis[Y] = y;
		draw_map(fdf, FREE);
	}
	if (fdf->keys.b_mouse_r)
	{
		fdf->map.source.axis[X] -= ((int)fdf->keys.last_click_r.axis[X] - x);
		fdf->map.source.axis[Y] -= ((int)fdf->keys.last_click_r.axis[Y] - y);
		fdf->map.source.axis[Z] = 0;
		fdf->keys.last_click_r.axis[X] = x;
		fdf->keys.last_click_r.axis[Y] = y;
		draw_map(fdf, FREE);
	}
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == 1)
		fdf->keys.b_mouse_l = 0;
	if (button == 2)
		fdf->keys.b_mouse_r = 0;
	return (0);
}

