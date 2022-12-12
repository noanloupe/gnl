/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:41:16 by noloupe           #+#    #+#             */
/*   Updated: 2022/12/12 18:03:10 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_extra_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*get_line(char *save, char *line, int *check, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_res;
	int		extra_size;

	read_res = 1;
	extra_size = BUFFER_SIZE;
	while (*check == 0 && read_res > 0)
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (read_res < 1)
		{
			free(line);
			ft_bzero(save, BUFFER_SIZE + 1);
			return (NULL);
		}
		if (check_char(buffer, '\n'))
		{
			extra_size = get_extra_size(buffer) + 1;
			*check = 1;
		}
		copy(save, &buffer[extra_size], BUFFER_SIZE + 1);
		line = join(line, buffer, extra_size);
	}
	return (line);
}

char	*save_dup(char *save, int *len, int *check)
{
	char	*line;
	int		i;
	int		count;

	if (!save)
		return (NULL);
	count = 0;
	i = 0;
	while (save[i] && save[count] != '\n')
	{
		i++;
		count++;
	}
	if (save[count] == '\n')
		*check = 1;
	line = malloc(sizeof(char) * count + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < count)
		line[i] = save[i];
	line[i] = '\0';
	*len = count;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*line;
	int			check;
	int			len;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	len = 0;
	check = 0;
	line = save_dup(save, &len, &check);
	copy(save, &save[len + 1], BUFFER_SIZE + 1);
	line = get_line(save, line, &check, fd);
	return (line);
}
