/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:16:54 by yazan             #+#    #+#             */
/*   Updated: 2023/01/03 17:13:51 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned int	i;

	d = dest;
	if (!dest && !src)
		return (NULL);
		i = 0;
	while (i < n)
	{
		*(d + i) = *(unsigned char *)src++;
		i++;
	}
	return (dest);
}

/* int main(void)
{
	char src[100] = "lets do that";
	char dest[100];
	ft_memcpy(dest,src,7);
	printf("1:%s\n,2:%s\n",src,dest);
	return (0);
} */