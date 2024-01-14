/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:26:13 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/15 00:42:06 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define char_read 1000000

char 	*read_map(int fd)
{
	static int	byte_read = char_read;
	static int	total_bytes = 0;
	char		*buffer;
	char		*map;

	buffer = malloc(char_read * sizeof(char));
	if (buffer == NULL)
		terminate(ALLOC_ERR);
	map = ft_strdup("");
	ft_printf("\n Map loading...\n\n");
	while (byte_read == char_read)
	{	
		ft_bzero (buffer, char_read);
		byte_read = read(fd, buffer, char_read);
		map = ft_strjoin(map, buffer);
		total_bytes += byte_read;
		ft_printf("\r %d kb reading", total_bytes / 1024);
	}
	printf("\r ✅ %d kb readed \n", total_bytes / 1024);
	free(buffer);
	return (map);
} 
//note: this function has more than 25 lines
 void	get_map_size(t_map *map)
{
	int			i;
	int			num_elem;
	static int	colmn_elem;
	static int	row_elem;

	i = -1;
	num_elem = 0;
	while (map->memory[++i])
	{
		if (map->memory[0] == '\n' && map->memory[1] == '\0')
			break ;
		if (ft_isalnum(map->memory[i]) && \
			(map->memory[i + 1] == ' ' || map->memory[i + 1] == '\n' || \
				map->memory[i + 1] == '\0'))
			num_elem++;
		if (map->memory[i] == '\n')
		{
			map->limits.axis[Y]++;
			if (colmn_elem != 0 && (num_elem != colmn_elem))
				terminate(ERR_HEX);
			else
				map->limits.axis[X] = num_elem;
			colmn_elem = num_elem;
			num_elem = 0;
		}
		if (map->memory[i] == '\n' && map->memory[i + 1] == '\0')
			break ;
	}
	printf(" \n✅number of x axis in each line:%d\n", colmn_elem);
	row_elem = map->limits.axis[Y];
	printf(" \n✅number of y axis in each line:%d\n", row_elem);
	map->len = row_elem * colmn_elem;
}

//note: this function has more than 25 lines
int	assign_points(char *line, t_map *map, int num_line)
{
	char		**tab;
	int			i;
	static int	index = 0;

	tab = ft_split(line, ' ');
	i = 0;
	while (tab[i] && tab[i][0] != '\n')
	{
		if (!valid_point(&tab[i][0]))
			terminate(FILE_ERR);
		map->points[index].axis[Z] = ft_atoi(&tab[i][0]);
		map->points[index].axis[X] = i - map->limits.axis[X] / 2;//5 4.5 4 3.5 3 2.5 2 1.5 1 0.5
		map->points[index].axis[Y] = num_line - map->limits.axis[Y] / 2;
		map->points[index].paint = 1;
		map->points[index].color = DEFAULT_COLOR;
		map->points[index].hex_color = if_hex_color(&tab[i][0]);
		if (map->limits.axis[Z] < map->points[index].axis[Z])
			map->limits.axis[Z] = map->points[index].axis[Z];
		if (map->zmin > map->points[index].axis[Z])
			map->zmin = map->points[index].axis[Z];
		i++;
		index++;
	}
	free_tab(tab);
	return (i);
}

void	get_map_points(t_map *map)
{
	int		i;
	int		points_number;
	int		num_line;
	char	*line;
	char	*full_line;

	num_line = 0;
	points_number = 0;
	line = NULL;
	full_line = map->memory;
	map->points = ft_calloc(map->len, sizeof(t_point));
	i = -1;
	while (1)
	{
		++i;
		if (map->memory[i] == '\n' || map->memory[i] == '\0')
		{
			free(line);
			line = ft_substr(full_line, 0, &map->memory[i] - full_line);
			full_line = map->memory + i + 1;
			points_number += assign_points(line, map, num_line++);
			ft_printf("\r 😈👓 (%d) pointss are being reading", points_number);
			if (map->memory[i] == '\0')
				break ;
		}
	}
	free(line);
	ft_printf("\r\n 💀👓 (%d) pointss are read", points_number);
}

void	load_map(t_map *map, char *av)
{
	int	fd;

	map_ini(map, 1);
	fd = open(av, O_RDONLY);
	if (fd < 3)
		terminate(FD_ERR);
	map->memory = read_map(fd);
	close(fd);
	get_map_size(map);
	get_map_points(map);
	colorize(map);
	get_polar(map);
	ft_printf("\nLoading GUI\n");
	map->renders = 0;
	map->proportion = map->limits.axis[Z] / map->limits.axis[X];
	if (map->proportion > 0.5)
		map->zdivisor = map->proportion * 50;
}
