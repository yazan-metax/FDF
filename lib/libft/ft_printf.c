/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:29:06 by yazan             #+#    #+#             */
/*   Updated: 2023/07/14 17:39:20 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format_pf(args, (char *)str, &counter);
		}
		else
			ft_putchar_pf(*str, &counter);
		str++;
	}
	va_end(args);
	return (counter);
}

/* int main(void)
{
	char str[100] = "\nhere we test out project";
	char *ptr;
	 
	ft_printf("here we shall see the result of my lovely project:
	 %s\n,%p\n,%%\n",str,ptr);
	return(0);
} */