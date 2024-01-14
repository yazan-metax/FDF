/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:01:27 by yazan             #+#    #+#             */
/*   Updated: 2023/05/07 15:14:50 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

sign = 1;
res = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' \
	|| *str == '\v' || *str == '\f' || *str == '\r'))
	str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		sign *= -1;
	str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str++ - '0');
	}
	return (res * sign);
}

/* int main() 
{
    char str[] = "   -42";
    printf("%d\n", ft_atoi(str));
    return 0;
} */
/* int		main(void)
{
	printf("%d\n", ft_atoi("				+--42"));

} */