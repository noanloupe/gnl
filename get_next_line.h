/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:28:47 by noloupe           #+#    #+#             */
/*   Updated: 2022/12/12 18:02:25 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		check_char(char *str, char c);
void	ft_bzero(char *s, int n);
void	copy(char *dst, char *src, int dstsize);
char	*join(char *s1, char *s2, int size);

#endif
