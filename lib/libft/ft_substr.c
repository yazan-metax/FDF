/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:41:39 by yazan             #+#    #+#             */
/*   Updated: 2023/01/14 18:06:22 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*src;
	size_t	reslen;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	src = (char *)s + start;
	if (ft_strlen(src) < len)
		reslen = ft_strlen(src) + 1;
	else
		reslen = len + 1;
	res = malloc(reslen * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, reslen);
	return (res);
}

/* char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    char    *substr;
		char 	*src;
		int res;

	src = (char *)s + start;
	if(ft_strlen(src) < len)
		res = ft_strlen(src) + 1;
	else
	res = len + 1;
    if (!s)
        return (NULL);
    if (start > strlen(s))
        return (strdup(""));
	substr = (char*)malloc(sizeof(char) * (res));
    if (!substr)
        return (NULL);
    ft_strlcpy(substr, src,res);
    return (substr);
} */

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;
	char *src;
	size_t n;
	
	src = (char *)s + start;
	if(!s)
		return (NULL);
	if(ft_strlen(s) < (size_t)start)
		return(strdup(""));
	if(ft_strlen(src) < len)
		n = ft_strlen(src) + 1;
		else
		n = len + 1;
	str = malloc(sizeof(char) * n );
	if(!str)
		return (NULL);
	ft_strlcpy(str, src, n);
	return (str);
} */
