/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:08:48 by noloupe           #+#    #+#             */
/*   Updated: 2022/12/07 14:34:52 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*join(char *s1, char *s2, int *size)
{
	char	*str;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	free(s1);
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (len > 0 && str[i - 1] == '\n')
	{
		*size = 0;
	}
	return (str);
}

void	cpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	
	if (!dst || !src || dstsize < 1)
		return ;
	i = 0;
	while (src[i] && i < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
}

char	*save_dup(const char *s1, int	*size)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		if (s1[len] == '\n')
		{
			++len;
			break;
		}
		++len;
	}
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s1[i];
	str[i] = '\0';
	if (len > 0 && str[i - 1] == '\n')
		*size = i - 1;
	return (str);
}
