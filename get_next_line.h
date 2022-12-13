/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:26:48 by noloupe           #+#    #+#             */
/*   Updated: 2022/12/13 15:28:54 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

char	*get_next_line(int fd);
void	copy(char *dst, char *src, int size);
void	ft_bzero(char *str, int size);
char	*join(char *line, char *buffer, int size);
int		ft_strlen(char *str);

#endif
