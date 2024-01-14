/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:26:32 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/11 18:22:43 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "fdf.h"

void	translate(t_point *point, int len, t_point trans);
void	scale(t_point *point, int len, int scale);
void	isometric(t_map *map);
void	bending(t_point *points, int len, float range);
void	parallel(t_map *map);
#endif
