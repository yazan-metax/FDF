/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:14:58 by yazan             #+#    #+#             */
/*   Updated: 2023/01/02 16:28:07 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;

	p = ptr;
	while (num--)
	{
	*p++ = (unsigned char) value;
	}
	return (ptr);
}
/* int main(void)
{
	char str[100] = "aaaaaaaabbbbbbbbbb";
	ft_memset(str,'A',8);
	printf("here is the result:%s\n",str);
	return (0);
} */