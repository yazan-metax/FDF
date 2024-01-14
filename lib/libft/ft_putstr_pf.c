/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:47:02 by yazan             #+#    #+#             */
/*   Updated: 2023/07/14 17:43:56 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_pf(char *str, size_t *counter)
{
	size_t	i;

i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		ft_putchar_pf(str[i], counter);
		i++;
	}
}
