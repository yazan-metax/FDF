/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:27:06 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/11 18:58:52 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "fdf.h"

void	orto_proyection(t_point *points, t_point *proyection, int len);
/* void	rotate_x(t_point *points, t_point *proyection, float ang, int len);
void	rotate_y(t_point *points, t_point *proyection, float ang, int len);
void	rotate_z(t_point *points, t_point *proyection, float ang, int len); */
void rotate_x(t_point *point,float angle,int len);
void rotate_y(t_point *point,float angle,int len);
void rotate_z(t_point *point,float angle,int len);
#endif
