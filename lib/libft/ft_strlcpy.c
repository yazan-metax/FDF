/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:54:03 by yazan             #+#    #+#             */
/*   Updated: 2023/01/08 15:58:48 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t sizedst)
{
	size_t	i;

	i = 0;
	if (sizedst > 0)
	{
		while (src[i] && i < sizedst - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
	i++;
	return (i);
}

/* int main(void)
{
	char src[100] = "lets do that";
	char dest[100];
	ft_strlcpy(dest,src,12);
	printf("1:%s\n,2:%s\n",src,dest);
	printf("the result:%zu\n",ft_strlcpy(dest,src,7));
	printf("dst later:%s\n",src);
	return (0);
} */