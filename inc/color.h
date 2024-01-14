/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:31:56 by yazan             #+#    #+#             */
/*   Updated: 2024/01/11 18:38:44 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "defines.h"

int		gradient(int startcolor, int endcolor, int len, int z);
void	get_color(int max_z, int mini_z, t_point *point, t_colors color);
void	colorize(t_map *map);
int		is_valid_hex_color(const char *color_str);
int		if_hex_color(char *line);
#endif