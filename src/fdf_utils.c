/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:50:27 by yazan             #+#    #+#             */
/*   Updated: 2024/01/12 00:25:22 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void	print_nbr(t_fdf *fdf, int x, int y, int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	mlx_string_put(fdf->win.mlx, fdf->win.win, x, y, NUMBER_COLOR, str);
	free (str);
}

void	print_str(t_fdf *fdf, int x, int y, char *str)
{
	mlx_string_put(fdf->win.mlx, fdf->win.win, x, y, TEXT_COLOR, str);
}

int ft_float_to_int(double num)
{
	int flip;
	flip = (int)num;
	if(num - flip >= .5)
		flip++;
	return(flip);
}

void	free_tab(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free (ptr);
}