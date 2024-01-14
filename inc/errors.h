/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:26:23 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/12 01:05:35 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#include <errno.h>

# define AV_ERR "ERROR❌,wrong number of arguments entered, it should be (❷) fdf with the name of the file"
# define FD_ERR "ERROR❌,there is a problem reading a file,(fd) is not correct"
# define ALLOC_ERR "ERROR❌,memory allocation failed"
# define AXIS_ERR "ERROR❌,wrong number of x elements,all colmns should be equal"
# define FILE_ERR "ERROR❌,file is wrongly formated,there is a non integer element in the file"
# define ERR_HEX		"❌Error, invalid hex color"
# define MAP_ERR		"❌Error drawing map"


void	terminate(char *s);

#endif
