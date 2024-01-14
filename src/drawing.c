/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:25:47 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/15 00:46:27 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void apply_geo(t_fdf *fdf,t_point *project)
{
	z_division(&fdf->map, project);
	applyTerrainElevation(project,fdf->map.len,0.1f,0.1f);
	if(fdf->map.sphere)
	{
		go_sphere(&fdf->map,project);
		fdf->map.proportion = fdf->map.limits.axis[Z] / fdf->map.limits.axis[X];
		if (fdf->map.proportion > 0.5)
			fdf->map.zdivisor = fdf->map.proportion * 100;
		
	}
	rotate_x(project,fdf->map.ang[X],fdf->map.len);
	rotate_y(project,fdf->map.ang[Y],fdf->map.len);
	rotate_z(project,fdf->map.ang[Z],fdf->map.len);
	if (fdf->map.sphere && fdf->map.b_shadow)
		shadow (project, fdf->map.len);
	orto_proyection (project, project, fdf->map.len);
	scale(project,fdf->map.len,fdf->map.scale);
	translate(project,fdf->map.len,fdf->map.source);
}

void	render_background(t_fdf *fdf, int backcolor, int menucolor)
{
	float	axis[2];
	int	pixel;
	int	color;

	backcolor = color_value(fdf, backcolor);
	menucolor = color_value(fdf, menucolor);
	axis[X] = 0;
	axis[Y] = 0;
	while (axis[Y] < WINY)
	{
		while (axis[X] < WINX)
		{
			if (axis[X] < MENU_WIDTH)
				color = menucolor;
			else
				color = backcolor;
			pixel = (axis[Y] * fdf->img.lines) + (axis[X] * 4);
			apply_color(&fdf->img.addr[pixel], \
						fdf->img.endian, color, 0);
			axis[X]++;
		}
		axis[Y]++;
		axis[X] = 0;
	}
}

void	init_drawing(t_fdf *fdf, t_point *proyect, int fit)
{
	if (fdf->map.b_stars)
		generate_stars(fdf);
	if (fit)
		fit_map(fdf, proyect);
	if (fdf->map.b_lines)
		preper_to_draw(fdf, proyect);
	if (fdf->map.b_dots)
		doted(fdf, proyect);
}

void	copy_map(t_point *src, t_point *dst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

int	draw_map(t_fdf *fdf, int fit)
{
	t_point	*proyect;
	clock_t	t;

	t = clock();
	proyect = malloc (fdf->map.len * sizeof(t_point));
	if (proyect == NULL)
		terminate(ALLOC_ERR);
	fdf->map.renders = fdf->map.renders + 1;
	copy_map(fdf->map.points, proyect, fdf->map.len);
	render_background(fdf, fdf->map.colors.background, \
	fdf->map.colors.menu);
	apply_geo(fdf, proyect);
	init_drawing(fdf, proyect, fit);
	mlx_put_image_to_window(fdf->win.mlx, fdf->win.win, \
	fdf->img.image, 0, 0);
	draw_menu(fdf);
	free (proyect);
	t= (double)(clock() - t);
	fdf->map.performance = ((double)t) / CLOCKS_PER_SEC;
	printf("time concumed:%f\n",fdf->map.performance);
	printf("renders value:%d\n",fdf->map.renders);
	return (1);
}
