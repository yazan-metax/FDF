/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:56:59 by yazan             #+#    #+#             */
/*   Updated: 2023/07/14 17:40:49 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	needle_len = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= needle_len)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle,
				needle_len) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}

/* int main (void)
{
	char str[200] = "This is a while loop that checks if the
	 current character in haystack is not the null character and if len is 
	 greater than or equal to needle_len";
	char needle[10] = "This";
	
	printf("here is the result:%s\n",ft_strnstr(str,needle,60));
	return (0);
} */
