/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:52:48 by yazan             #+#    #+#             */
/*   Updated: 2023/07/14 16:50:21 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	ptr_adress;

	ptr_adress = (unsigned long)ptr;
	ft_putstr_pf("0x", counter);
	str = ft_aux_pf(ptr_adress, HEX_LOW_BASE);
	ft_putstr_pf(str, counter);
	free(str);
}
