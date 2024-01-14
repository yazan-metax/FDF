/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:32:44 by yazan             #+#    #+#             */
/*   Updated: 2023/01/08 04:20:31 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (n > 0)
	{
		if (*s == (unsigned char)c)
			return ((void *)s);
		s++;
		n--;
	}
	return (NULL);
}

/* int main(void)
{
    char str[] = "Hello, World!";
    char c = 'o';
    size_t n = 5;
    void *result;

    result = ft_memchr(str, c, n);
    if (result != NULL)
    {
        printf("Character '%c' found at index %ld\n", c, (char *)result - str);
    }
    else
    {
        printf("Character '%c' not found\n", c);
    }

    return 0;
} */