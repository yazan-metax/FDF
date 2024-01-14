/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:34:10 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/15 00:39:21 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

int	valid_point(char *value)
{
	int	valid;

	valid = 0;
	if (*value == '-' || *value == '+' || ft_isdigit(*value))
		valid++;
	value++;
	while (ft_isdigit(*value))
	{
		value++;
		valid++;
	} 
	if (valid == 0)
		return (0);
	else
		return (1);
}

void z_division(t_map *map,t_point *project)
{
	int i;

	i = 0;
	while(i < map->len)
	{
		project[i].axis[Z] = project[i].axis[Z] / map->zdivisor;
		i++;
	}
}

static void	map_init_colors(t_map *map)
{
	map->colors.background = BACKGROUND_COLOR;
	map->colors.menu = MENU_COLOR;
	map->colors.bottom = BOTTOM_COLOR;
	map->colors.ground = GROUND_COLOR;
	map->colors.top = TOP_COLOR;
}

void	map_ini(t_map *map,int total)
{
	if (total)
	{
		map->len = 0;
		map->limits.axis[X] = 0;
		map->limits.axis[Y] = 0;
		map->limits.axis[Z] = 0;
		map->zmin = 0;
	}
	map->b_lines = 1;
	map->b_dots = 0;
	map->b_pluslines = 1;
	map->sphere = 0;
	map->b_stars = 0;
	map->b_shadow = 1;
	map->scale = 1;
	map->zdivisor = 1;
	map->brange = 0;
	map->source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y] = WINY / 2;
	map->source.axis[Z] = 0;
	map->renders = 0;
	map->ang[X] = 0;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
	map->m_terrain = 1;
	map->scale = 1;
	map_init_colors(map);
}
