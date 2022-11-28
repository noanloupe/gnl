/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:19:28 by noloupe           #+#    #+#             */
/*   Updated: 2022/11/28 14:36:06 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static void	get_buffer(int fd, char **line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_res;

	read_res = 1;
	while (read_res > 0 && !check_char(*line, '\n'))
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		buffer[read_res] = '\0';
		*line = ft_strjoin(*line, buffer);
	}
}

static char	*set_save(char *line, char *save)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		i++;
	}
	if (line[i] == '\n')
		i++;
	while (line[i] != '\0')
	{
		save[j] = line[i];
		i++;
		j++;
	}
	save[j] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	if (*save)
		line = ft_strdup(save);
	else
		line = "";
	get_buffer(fd, &line);
	save = set_save(line, save);
	return (line);
}
