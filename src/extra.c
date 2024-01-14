/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:09:11 by yazan             #+#    #+#             */
/*   Updated: 2024/01/15 00:40:29 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"
# include "../inc/drawing.h"

void	doted(t_fdf *fdf, t_point *proyect)
{
	int	i;

	i = 0;
	while (i < fdf->map.len)
	{
		if (proyect[i].paint)
			draw_dot(fdf, proyect[i], 1);
		i++;
	}
}

static void	dot_util(t_fdf *fdf, t_point pixel, t_point point, int coord)
{
	int	i;

	i = point.axis[X];
	while (i <= point.axis[X] + coord)
	{
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)point.axis[Y] + coord;
		my_putpixel(fdf, pixel);
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)point.axis[Y] - coord;
		my_putpixel(fdf, pixel);
		i++;
	}
}

void	draw_dot(t_fdf *fdf, t_point point, int radius)
{
	int		axis[2];
	int		change[2];
	int		radius_error;
	t_point	pixel;

	axis[X] = radius;
	axis[Y] = 0;
	change[X] = 1 - (radius << 1);
	change[Y] = 0;
	radius_error = 0;
	pixel.color = point.color;
	while (axis[X] >= axis[Y])
	{
		dot_util(fdf, pixel, point, axis[Y]);
		dot_util(fdf, pixel, point, axis[X]);
		axis[Y]++;
		radius_error += change[Y];
		change[Y] += 2;
		if (((radius_error << 1) + change[X]) > 0)
		{
			axis[X]--;
			radius_error += change[X];
			change[X] += 2;
		}
	}
}

void	shadow(t_point *points, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (points[i].axis[Z] < 0)
			points[i].paint = 0;
		else
			points[i].paint = 1;
		i++;
	}
}

void applyTerrainElevation(t_point *points, int len, float frequency, float amplitude)
{
  int i;
  float z;
	
	i = 0;
  while(i > len) {
    float x = points[i].axis[X];
    float y = points[i].axis[Y];
    float xSquared = x * x;
    float ySquared = y * y;
    z = amplitude * (xSquared + ySquared) * frequency;
    points[i].axis[Y] += z;
		i++;
    }
}

void	generate_stars(t_fdf *fdf)
{
	int		i;
	t_point	star;
	int		lim_x[2];
	int		lim_y[2];

	if (fdf->map.sphere == 0)
		return ;
	lim_x[0] = fdf->map.source.axis[X] - (fdf->map.radius * fdf->map.scale);
	lim_x[1] = fdf->map.source.axis[X] + (fdf->map.radius * fdf->map.scale);
	lim_y[0] = fdf->map.source.axis[Y] - (fdf->map.radius * fdf->map.scale);
	lim_y[1] = fdf->map.source.axis[Y] + (fdf->map.radius * fdf->map.scale);
	i = 0;
	while (i < 200)
	{
		star.axis[X] = rand() % WINX;
		star.axis[Y] = rand() % WINY;
		star.color = WHITE;
		if ((star.axis[X] < lim_x[0] || star.axis[X] > lim_x[1]) \
		|| ((star.axis[Y]) < lim_y[0] || star.axis[Y] > lim_y[1]))
			draw_dot(fdf, star, 2);
		i++;
	}
}