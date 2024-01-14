/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:42:31 by yazan             #+#    #+#             */
/*   Updated: 2023/07/14 17:42:43 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 == '\0' && *str2 == '\0')
		{
			return (0);
		}
		else if (*str1 != *str2)
		{
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		}
		str1++;
		str2++;
		n--;
	}
	return (0);
}

/* int	main(void)
{
	char	str1[100] = "abcd";
	char	str2[100] = "";

	printf("here is the result:%d\n", ft_strncmp(str1, str2, ft_strlen(str1)));
	return (0);
} */