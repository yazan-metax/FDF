/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:28:01 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/11 23:54:04 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_UTILS_H
# define DRAW_UTILS_H

# include "fdf.h"

int		draw_line(t_fdf *fdf, t_point start, t_point end);
int		gradient(int startcolor, int endcolor, int len, int z);
int		my_putpixel(t_fdf *fdf, t_point pixel);
void	preper_to_draw(t_fdf *fdf, t_point *point);
int		color_value(t_fdf *fdf, int color);
void	apply_color(char *buffer, int endian, int color, int alpha);
int		check_margin(t_point *point, int len);
void	fit_map(t_fdf *fdf, t_point *proyect);
void	render_background(t_fdf *fdf, int backcolor, int menucolor);
void 	apply_geo(t_fdf *fdf,t_point *project);


#endif
