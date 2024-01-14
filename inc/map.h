/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:26:51 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/11 23:54:43 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

int		draw_map(t_fdf *fdf, int fit);
void	load_map(t_map *map, char *path);
void	draw_menu(t_fdf *fdf);
void	map_ini(t_map *map, int total);
void	generate_stars(t_fdf *fdf);
int		valid_point(char *value);
void 	z_division(t_map *map,t_point *project);
#endif
