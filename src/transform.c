/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:02:13 by ailopez-          #+#    #+#             */
/*   Updated: 2024/01/11 16:16:46 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

t_point multiply_matrix(t_point point,float matrix[3][3])
{
	int j;
	int i;
	t_point new_point;

	new_point = point;
	i = 0;
	while(i < 3)
	{
		new_point.color = point.color;
		new_point.axis[i] = 0;
		j = 0;
		while(j < 3)
		{
			new_point.axis[i] += matrix[i][j] * point.axis[j];
			j++;
		}
		i++;
	}
	return(new_point);
}

void rotate_x(t_point *point,float angle,int len)
{
	int i;
	float rad;
	float rotate_matrix[3][3];

	i = 0;
	rad = angle * (M_PI / 180);
	matrix_init(rotate_matrix);
	rotate_matrix[0][0] = 1;
	rotate_matrix[1][1] = cos(rad);
	rotate_matrix[1][2] = -sin(rad);
	rotate_matrix[2][1] = sin(rad);
	rotate_matrix[2][2] = cos(rad);
	while(i < len)
	{
		point[i] = multiply_matrix(point[i],rotate_matrix);
		i++;
	}
}

void rotate_y(t_point *point,float angle,int len)
{
	int i;
	float rad;
	float rotate_matrix[3][3];

	i = 0;
	rad = angle * (M_PI / 180);
	matrix_init(rotate_matrix);
	rotate_matrix[0][0] = cos(rad);
	rotate_matrix[0][2] = sin(rad);
	rotate_matrix[1][1] = 1;
	rotate_matrix[2][0] = -sin(rad);
	rotate_matrix[2][2] = cos(rad);
	while(i < len)
	{
		point[i] = multiply_matrix(point[i],rotate_matrix);
		i++;
	}
}

void rotate_z(t_point *point,float angle,int len)
{
	int i;
	float rad;
	float rotate_matrix[3][3];

	i = 0;
	rad = angle * (M_PI / 180);
	matrix_init(rotate_matrix);
	rotate_matrix[0][0] = cos(rad);
	rotate_matrix[0][1] = -sin(rad);
	rotate_matrix[1][0] = sin(rad);
	rotate_matrix[1][1] = cos(rad);
	rotate_matrix[2][2] = 1;
	while(i < len)
	{
		point[i] = multiply_matrix(point[i],rotate_matrix);
		i++;
	}
}

void	orto_proyection(t_point *points, t_point *proyection, int len)
{
	int		i;
	float	proyect_matrix[3][3];

	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = 1;
	proyect_matrix[1][1] = 1;
	i = 0;
	while (i < len)
	{
		proyection[i] = multiply_matrix(points[i],proyect_matrix);
		i++;
	}
}
