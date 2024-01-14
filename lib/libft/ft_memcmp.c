/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:45:41 by yazan             #+#    #+#             */
/*   Updated: 2023/01/08 17:22:14 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const char *str1, const char *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (n--)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

/* int main(void)
{
	 char str1[100] = "ABCD";
	 char str2[100] = "ABCd";
	printf("here is the result:%d\n",ft_memcmp(str1,str2,4));
	return (0);
} */