/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:41:18 by yazan             #+#    #+#             */
/*   Updated: 2024/01/15 00:51:36 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	gradient(int startcolor, int endcolor, int len, int z)
{
	double	difference[3];
	int		new[3];
	int		color;

	difference[0] = ((double)(endcolor >> 16) - \
						(startcolor >> 16)) / \
		(double)len;
	difference[1] = (double)(((endcolor >> 8) & 0xFF) - \
								((startcolor >> 8) & 0xFF)) / \
		(double)len;
	difference[2] = (double)((endcolor & 0xFF) - (startcolor & 0xFF))
		/ (double)len;
	new[0] = (startcolor >> 16) + ft_float_to_int(z * difference[0]);
	new[1] = ((startcolor >> 8) & 0xFF) + ft_float_to_int(z * difference[1]);
	new[2] = (startcolor & 0xFF) + ft_float_to_int(z * difference[2]);
	color = ((new[0] << 16) + (new[1] << 8) + new[2]);
	return (color);
}

void	get_color(int max_z, int mini_z, t_point *point, t_colors color)
{
	point->paint = 1;
	point->color = DEFAULT_COLOR;
	if (point->hex_color > 0)
	{
		point->color = point->hex_color;
		return ;
	}
	if (point->axis[Z] == max_z)
		point->color = TOP_COLOR;
	if (point->axis[Z] == mini_z && mini_z != 0)
		point->color = BOTTOM_COLOR;
	if (point->axis[Z] == 0)
		point->color = GROUND_COLOR;
	if (point->axis[Z] > 0)
		point->color = gradient(color.ground, color.top, max_z, point->axis[Z]);
	if (point->axis[Z] < 0)
		point->color = gradient(color.bottom, color.ground, -mini_z, -(mini_z
					- point->axis[Z]));
}

void	colorize(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		get_color(map->limits.axis[Z], map->zmin, &map->points[i], map->colors);
		i++;
	}
}

int	is_valid_hex_color(const char *color_str)
{
	if (!color_str || *color_str == '\0')
	{
		terminate(ERR_HEX);
		return (0);
	}
	if (color_str[0] == '0' && (color_str[1] == 'x' || color_str[1] == 'X'))
	{
		color_str += 2;
	}
	while (*color_str)
	{
		if (!((*color_str >= '0' && *color_str <= '9') || \
				(*color_str >= 'a' && *color_str <= 'f') || \
				(*color_str >= 'A' && *color_str <= 'F')))
		{
			terminate(ERR_HEX);
			return (0);
		}
		color_str++;
	}
	return (1);
}

int	if_hex_color(char *line)
{
	char	**get_color;
	int		color;

	color = 0;
	if (ft_strchr(line, ',') != NULL)
	{
		get_color = ft_split(line, ',');
		if (get_color[0] && get_color[1] && is_valid_hex_color(get_color[1]))
			color = strtol(get_color[1], NULL, 16);
		return (color);
		free_tab(get_color);
	}
	else
		return (0);
}
