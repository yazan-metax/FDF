/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:27:13 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/11 23:54:59 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	free_tab(char **ptr);
int 	ft_float_to_int(double num);
void	matrix_init(float (*matrix)[3]);
void	print_nbr(t_fdf *fdf, int x, int y, int nbr);
void	print_str(t_fdf *fdf, int x, int y, char *str);
void	copy_map(t_point *src, t_point *dst, int len);
int		valid_pixel(t_point pixel);
#endif
