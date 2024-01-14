/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:49:26 by yazan             #+#    #+#             */
/*   Updated: 2023/01/17 14:58:42 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*start;
	char	*end;
	char	*res;

	start = (char *) s1;
	end = start + ft_strlen(s1);
	if (!s1 || !set)
		return (0);
	while (*start && ft_strrchr(set,*start))
	++start;
	while (start < end && ft_strrchr(set, *(end - 1)))
	--end;
	res = ft_substr(start, 0, end - start);
	return (res);
}
