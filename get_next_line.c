/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:17:23 by noloupe           #+#    #+#             */
/*   Updated: 2022/11/23 11:16:45 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

#include "get_next_line.h"
#include <stdio.h>

static char	*clear_buffer(char *save)
{
	char	*str;
	size_t	len;

	printf("\nsave: [%s]\n", save);
	len = 0;
	while (save[len] != '\n' && save[len] != '\0')
		++len;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (*save != '\n' && *save != '\0')
		*++str = *++save;
	*str = '\0';
	printf("\nSTR: [%s]\n", str);
	return (str);
}

static char	*get_buffer(int fd, char *save)
{
	int		read_res;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
//	printf("TEST\n");
	read_res = 1;
	while (!check_char(save, '\n') && read_res != 0)
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		if (read_res <= 0)
		{
			free(buffer);
			return(NULL);
		}
		printf("\nBUFFER: [%s]\n", buffer);
		save = ft_strjoin(save, buffer);
		printf("\nSAVE: [%s]\n", save);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char	*str;
	static char *save;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	save = malloc(1);
	free(save);
	save = get_buffer(fd, &*save);
	if (!save)
	{
		return (NULL);
	}
	str = clear_buffer(save);
	return (str);
}
