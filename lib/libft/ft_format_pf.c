/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:17:56 by yazan             #+#    #+#             */
/*   Updated: 2023/07/14 16:49:35 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_format_pf(va_list args, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(args, int), counter);
	else if (*str == 's')
		ft_putstr_pf(va_arg(args, char *), counter);
	else if (*str == 'p')
		ft_putptr_pf(va_arg(args, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr_pf(va_arg(args, int), counter);
	else if (*str == 'u')
		ft_putdec_pf(va_arg(args, unsigned int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_puthex_pf(va_arg(args, unsigned int), counter, HEX_LOW_BASE);
		if (*str == 'X')
			ft_puthex_pf(va_arg(args, unsigned int), counter, HEX_UPP_BASE);
	}
	else if (*str == '%')
		ft_putchar_pf(*str, counter);
}
