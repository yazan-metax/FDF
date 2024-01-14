/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:51:43 by ailopez-          #+#    #+#             */
/*   Updated: 2024/01/10 17:54:19 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*read_func(int fd, char *str)
{
	char	*tmp;
	int		bytes;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = 42;
	while (!ft_strchr_g(str, '\n') && (bytes != 0))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes] = '\0';
		str = ft_strjoin_g(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*get_line(char *full_str)
{
	int		i;
	char	*line;

	i = 0;
	if (!full_str[i])
		return (NULL);
	while (full_str[i] && full_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	if (full_str[i] == '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *full_Str)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (full_Str[i] != '\n' && full_Str[i])
		i++;
	if (!full_Str[i])
	{
		free(full_Str);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen_g(full_Str) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (full_Str[i])
	{
		rest[j++] = full_Str[i++];
	}
	rest[j] = '\0';
	free(full_Str);
	return (rest);
}

char	*get_next_line(int fd)
{
	char static	*full_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	full_str = read_func(fd, full_str);
	if (!full_str)
		return (NULL);
	line = get_line(full_str);
	full_str = get_rest(full_str);
	return (line);
}

/* int	main(void)
{
	int fd;
    char *tab;
    fd = open("test1.txt", O_RDONLY);
    tab = get_next_line(fd);
    printf("%s", tab);
    free(tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    close(fd);
	return (0);
} */