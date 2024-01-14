/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:47:35 by yazan             #+#    #+#             */
/*   Updated: 2024/01/10 19:21:42 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

size_t	ft_strlen_g(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_g(char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen_g(str)]);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_g(char *str1, char *str2)
{
	int		x;
	int		y;
	char	*str;

	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen_g(str1) + ft_strlen_g(str2))
			+ 1);
	if (str == NULL)
		return (NULL);
	x = -1;
	y = 0;
	while (str1[++x] != '\0')
		str[x] = str1[x];
	while (str2[y] != '\0')
		str[x++] = str2[y++];
	str[ft_strlen_g(str1) + ft_strlen_g(str2)] = '\0';
	free(str1);
	return (str);
}