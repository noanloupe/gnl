/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:19:28 by noloupe           #+#    #+#             */
/*   Updated: 2022/12/07 14:45:21 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	len_checker(char *buffer)
{
	int	len_check;
	
	len_check = 0;
	while (buffer[len_check])
	{
		if (buffer[len_check] == '\n')
		{
			++len_check;
			break;
		}
		++len_check;
	}
	return (len_check);
}

static char	*get_line(int fd, char *line, char *save, int *size)
{
	int		read_res;
	int		len_check;
	char	buffer[BUFFER_SIZE + 1];

	while (*size == -1)
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(line);
			return (NULL);
		}
		len_check = len_checker(buffer);
		cpy(save, &buffer[len_check], BUFFER_SIZE + 1);
		cpy(buffer, buffer, len_check + 1);
		line = join(line, buffer, size);
		if (read_res == 0)
			break;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*line;
	int			size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	size = -1;
	line = save_dup(save, &size);
	if (!line)
		return (NULL);
	cpy(save, &save[size + 1], BUFFER_SIZE + 1);
	line = get_line(fd, line, save, &size);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
