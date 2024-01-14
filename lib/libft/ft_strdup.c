/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:17:17 by yazan             #+#    #+#             */
/*   Updated: 2023/01/12 21:53:05 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*str;
	unsigned int	i;
	unsigned int	c;

i = 0;
c = ft_strlen(s) + 1;
str = (char *)malloc(sizeof(*s) * c);
	if (!s)
		return (NULL);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
	i++;
	}
	str[i] = 0;
	return (str);
}

/* int main(void)
{
	char str[20] = "hey avy i love you";
	
	printf("here is the duplicated string: %s\n",ft_strdup(str));
	return (0);
} */