/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:09:51 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/12 00:26:02 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

int	color_value(t_fdf *fdf, int color)
{	
	if (fdf->img.bitxpixel != 32)
		color = mlx_get_color_value(fdf->win.mlx, color);
	return (color);
}

void	apply_color(char *buffer, int endian, int color, int alpha)
{
	if (endian == 1)
	{
		buffer[0] = alpha;
		buffer[1] = (color >> 16) & 0xFF;
		buffer[2] = (color >> 8) & 0xFF;
		buffer[3] = (color) & 0xFF;
	}
	else
	{
		buffer[0] = (color) & 0xFF;
		buffer[1] = (color >> 8) & 0xFF;
		buffer[2] = (color >> 16) & 0xFF;
		buffer[3] = alpha;
	}
}

int check_margin(t_point *point,int len)
{
	int i;

	i = 0;
	while(i < len)
	{
		if(point[i].axis[X] < (MENU_WIDTH + FIT_MARGIN) ||point[i].axis[X] > (WINX - FIT_MARGIN))
			return(1);
		if(point[i].axis[Y] <FIT_MARGIN || point[i].axis[Y] > (WINY - FIT_MARGIN))
				return(1);
		i++;
	}
	return(0);
}

void	fit_map(t_fdf *fdf, t_point *proyect)
{
	fdf->map.source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	fdf->map.source.axis[Y] = WINY / 2;
	fdf->map.source.axis[Z] = 0;
	fdf->map.scale = 1;
	copy_map(fdf->map.points, proyect, fdf->map.len);
	apply_geo(fdf, proyect);
	while (!(check_margin(proyect, fdf->map.len)))
	{
		copy_map(fdf->map.points, proyect, fdf->map.len);
		apply_geo(fdf, proyect);
		fdf->map.scale += 0.5;
	}
}

