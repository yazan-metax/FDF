/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:26:10 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/12 01:03:13 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_UTILS_H
# define CONTROL_UTILS_H

# include "defines.h"

void	angle_control(int key, t_fdf *fdf);
void	angle(float *ang, float value);
int		terminate_program(void *param);
void	terminate(char *s);
void	control_colorscheme(int key, t_map *map);
int		mouse_move(int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_press(int button, int x, int y, void *param);
int		key_press(int key, void *param);
int		key_release(int key, void *param);
#endif
