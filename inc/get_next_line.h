/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:52:14 by ailopez-          #+#    #+#             */
/*   Updated: 2024/01/10 17:55:07 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>


size_t ft_strlen_g(char *s);
char	*ft_strchr_g(char *s, int c);
char	*ft_strjoin_g(char *left_str, char *buff);
char	*get_line(char *str);
char	*get_rest(char *str);
char	*read_func(int fd, char *str);
char	*get_next_line(int fd);

#endif
