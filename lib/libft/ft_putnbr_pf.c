/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:42:53 by yazan             #+#    #+#             */
/*   Updated: 2023/07/14 16:50:14 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	ft_putnbr_pf(int num, size_t *counter)
{
	int	i;

	i = -1;
	if (num == -2147483648)
	{
		ft_putstr_pf("-2147483648", counter);
		return ;
	}
	else if (num < 0)
	{
		ft_putchar_pf('-', counter);
		num *= i;
	}
	else if (num > 9)
	{
		ft_putnbr_pf(num / 10, counter);
		ft_putchar_pf(num % 10 + 48, counter);
	}
	else
	{
		ft_putchar_pf(num + 48, counter);
	}
} */
void	ft_putnbr_pf(int num, size_t *counter)
{
	if (num == -2147483648)
	{
		ft_putnbr_pf((num / 10), counter);
		ft_putchar_pf('8', counter);
	}
	else if (num < 0)
	{
		ft_putchar_pf('-', counter);
		ft_putnbr_pf(-num, counter);
	}
	else if (num > 9)
	{
		ft_putnbr_pf((num / 10), counter);
		ft_putchar_pf(('0' + num % 10), counter);
	}
	else
	{
		ft_putchar_pf(num % 10 + 48, counter);
	}
}
