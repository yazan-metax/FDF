/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:36:55 by ailopez-          #+#    #+#             */
/*   Updated: 2024/01/15 00:23:50 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

int	main(int argv, char **argc)
{
	t_fdf	fdf;
	
	if (argv != 2)
		terminate(AV_ERR);
	load_map(&fdf.map, argc[1]);
	fdf.win.mlx = mlx_init();
	fdf.win.win = mlx_new_window(fdf.win.mlx, WINX, WINY, \
	"yazan-metax");
	fdf.img.image = mlx_new_image(fdf.win.mlx, WINX, WINY);
	fdf.img.addr = mlx_get_data_addr(fdf.img.image, \
		&fdf.img.bitxpixel, &fdf.img.lines, &fdf.img.endian);
	if (draw_map(&fdf, FIT) < 0)
		terminate(MAP_ERR);
	mlx_hook(fdf.win.win, 2, 0, key_press, &fdf);
	mlx_hook(fdf.win.win, 3, 0, key_release, &fdf);
	mlx_hook(fdf.win.win, 4, 0, mouse_press, &fdf);
	mlx_hook(fdf.win.win, 5, 0, mouse_release, &fdf);
	mlx_hook(fdf.win.win, 6, 0, mouse_move, &fdf);
	mlx_hook(fdf.win.win, 17, 0, terminate_program, &fdf);
	mlx_loop(fdf.win.mlx);
	free (fdf.map.points);
	free (fdf.map.memory);
	return (0);
}
