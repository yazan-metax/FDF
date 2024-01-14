/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:30:51 by aitoraudi         #+#    #+#             */
/*   Updated: 2024/01/12 01:01:29 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void go_sphere(t_map *map,t_point *point)
{
	int i;
	
	i = 0;
	while(i < map->len)
	{
		point[i].axis[X] = (map->radius + point[i].axis[Z]) *\
		cos(point[i].polar[LONG]) * sin(point[i].polar[LAT]);
		point[i].axis[Y] = (map->radius + point[i].axis[Z]) * \
		sin(point[i].polar[LONG]) * sin(point[i].polar[LAT]);
		point[i].axis[Z] = ((map->radius) * cos(point[i].polar[LAT]));
		i++;
	}
}

void calculate_radius(t_map *map)
{
    float max_dimension;
		
		if(map->limits.axis[Y] > map->limits.axis[X])
			max_dimension = map->limits.axis[Y];
		else 
			max_dimension = map->limits.axis[X];
    map->radius = (max_dimension / ( M_PI * 2)) * map->zdivisor;
} 

void get_polar(t_map *map)
{
	float latitude;
	float longitude;
	float ang_steps_x;
	int i;

	ang_steps_x = (M_PI * 2) / (map->limits.axis[X] - 1);
	calculate_radius(map);
	i = 0;
	while(i < map->len)
	{
		longitude = map->points[i].axis[X] * ang_steps_x - M_PI;
		latitude = (map->points[i].axis[Y] /map->limits.axis[Y] - 0.5) * M_PI;
		map->points[i].polar[LAT] = latitude;
		map->points[i].polar[LONG] = longitude;
		i++;
	}
}



