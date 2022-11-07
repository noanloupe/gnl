/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:08:48 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/25 16:49:58 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str)
	{
		++str;
		++i;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*str;
	size_t			i;
	size_t			j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[++i] = s2[j];
	str[i] = '\0';
	return (str);
}

size_t	check_char(const char *s, const char c)
{
	if (!s || !c)
		return (0);
	while (*s && *s != c)
		++s;
	if (*s == c)
		return (1);
	return (0);
}
