/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:00:11 by yazan             #+#    #+#             */
/*   Updated: 2023/01/25 16:44:09 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n && ++count)
		n /= 10;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	char	*dig;

	dig = "0123456789";
	len = ft_numlen(n);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (n)
	{
		if (n > 0)
			res[--len] = dig[n % 10];
		else
			res[--len] = dig[n % 10 * -1];
		n /= 10;
	}
	return (res);
}

/* int	main(void)
{
	printf("here is the result :%s\n", ft_itoa(-12345));
	printf("here is the 2.result :%d\n", ft_numlen(-12345));
	return (0);
} */