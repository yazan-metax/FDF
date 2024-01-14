/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:01:10 by ailopez-          #+#    #+#             */
/*   Updated: 2024/01/15 00:40:46 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void translate(t_point *point,int len,t_point trans)
{
	int i;

	i = 0;
	while(i < len)
	{
		point[i].axis[X] += trans.axis[X];
		point[i].axis[Y] += trans.axis[Y];
		point[i].axis[Z] += trans.axis[Z];
		i++;
	}
}

void scale(t_point *point,int len,int scale)
{
	int i;

	i = 0;
	while(i < len)
	{
		point[i].axis[X] *= scale;
		point[i].axis[Y] *= scale;
		point[i].axis[Z] *= scale;
		i++;
	}
}

void	isometric(t_map *map)
{
	map->sphere = 0;
	map->ang[X] = 30;
	map->ang[Y] = 330;
	map->ang[Z] = 30;
	map->brange = 0;
	map->source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y] = WINY / 2;
}

void	parallel(t_map *map)
{
	map->sphere = 0;
	map->ang[X] = 90;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
	map->brange = 0;
	map->source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y] = WINY / 2;
}