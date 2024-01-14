/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:24:54 by yazan             #+#    #+#             */
/*   Updated: 2024/01/10 19:27:00 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLAR_H
# define POLAR_H
#include "fdf.h"

void get_polar(t_map *map);
void calculate_radius(t_map *map);
void go_sphere(t_map *map,t_point *point);

# endif