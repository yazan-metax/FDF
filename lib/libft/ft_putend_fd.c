/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putend_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:10:27 by yazan             #+#    #+#             */
/*   Updated: 2023/10/03 15:20:01 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putend_fd(const char *s,int fd)
{
	if(!s)
		return;
	write(fd,s,ft_strlen(s));
	write(fd,"\n",1);
}