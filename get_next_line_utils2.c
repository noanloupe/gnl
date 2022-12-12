/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:41:48 by noloupe           #+#    #+#             */
/*   Updated: 2022/12/12 18:03:52 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_bzero(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

void	copy(char *dst, char *src, int dstsize)
{
	int	i;

	if (dstsize < 1)
		return ;
	i = 0;
	while (src[i] && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*join(char *s1, char *s2, int size)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * ft_strlen(s1) + size + 1);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (j < size)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	if (str[i - 1] == '\n')
		str[i - 1] = '\0';
	return (str);
}
