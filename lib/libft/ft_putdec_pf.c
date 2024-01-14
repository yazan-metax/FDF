/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:06:14 by yazan             #+#    #+#             */
/*   Updated: 2023/07/14 16:49:57 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdec_pf(unsigned int num, size_t *counter)
{
	char	*str;

	str = ft_aux_pf(num, "0123456789");
	ft_putstr_pf(str, counter);
	free(str);
}
