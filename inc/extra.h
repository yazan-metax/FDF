/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:18:05 by yazan             #+#    #+#             */
/*   Updated: 2024/01/14 15:40:21 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_H
#define EXTRA_H

# include "fdf.h"

void 	applyTerrainElevation(t_point *points, int len, float frequency, float amplitude);
void	shadow(t_point *points, int len);
void	draw_dot(t_fdf *fdf, t_point point, int radius);
void	doted(t_fdf *fdf, t_point *proyect);

#endif