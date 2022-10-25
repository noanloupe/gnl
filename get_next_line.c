/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:17:23 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/25 16:50:15 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

#include "get_next_line.h"


char	*get_buffer(int fd, char *save)
{
	int		read_res;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_res = 1;
	while (!check_char(save, '\n') && read_res != 0)
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		if (read_res <= 0)
		{
			free(buffer);
			return(NULL);
		}
		save = ft_strjoin(save, buffer);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char	*str;
	static char *save;

	if (fd < 0 || BUFFER_SIZE < 0)
		return NULL;
	save = get_buffer(fd, &save);
	if (!save)
	{
		return (NULL);
	}
	return (str);
}

#include <stdio.h>
int	main()
{
	printf("%s\n", get_next_line(0));
}
