/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:44:35 by noloupe           #+#    #+#             */
/*   Updated: 2022/12/07 14:42:53 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
//	int		fd2;
//	int		fd3;
	char	*test1;
//	char	*test2;
//	char	*test3;
	int		i;

	i = 1;
	fd1 = open("test.txt", O_RDONLY);
//	fd2 = open("JKRowling_HP1.txt", O_RDONLY);
//	fd3 = open("king_james_bible.txt", O_RDONLY);
	test1 =  malloc(1);
//	test2 =  malloc(1);
//	test3 =  malloc(1);
	while (i < 3)
	{
		free(test1);
//		free(test2);
//		free(test3);
		test1 = get_next_line(fd1);
//		test2 = get_next_line(fd2);
//		test3 = get_next_line(fd3);
		printf("%d:%s", i, test1);
		printf("\n");
//		printf("%d:%s", i, test2);
//		printf("\n");
//		printf("%d:%s", i, test3);
//		printf("\n");
		i++;
	}	
	close(fd1);
//	close(fd2);
//	close(fd3);
//	system("leaks a.out");
}
