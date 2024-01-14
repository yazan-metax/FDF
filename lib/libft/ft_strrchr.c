/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:29:18 by yazan             #+#    #+#             */
/*   Updated: 2023/02/01 00:25:50 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			last = (char *)s;
		}
		s++;
	}
	if (*s == (char)c)
	{
		last = (char *)s;
	}
	return (last);
}

/* int main(void)
{
    char str[] = "Hello,World!";
    char c = 'o';
    void *result;

    result = ft_strrchr(str, c);
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