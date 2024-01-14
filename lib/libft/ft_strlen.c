/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:33:50 by yazan             #+#    #+#             */
/*   Updated: 2022/12/30 15:54:00 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (*s++)
	{
		x++;
	}
	return (x);
}
/* int main(void)
{
	char str[] = "hello mf, 	";
	size_t len;
	len = ft_strlen(str);
	printf("here is the length of str:%zu\n",len);
	return (0);
} */