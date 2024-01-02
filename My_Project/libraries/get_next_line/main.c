/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:52:31 by uviana-a          #+#    #+#             */
/*   Updated: 2023/05/31 20:52:34 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*file;
	char	*test;
	int		i;
	int		fd;

	i = 0;
	file = "test.txt";
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: the file couldn't be opened!\n");
		return (1);
	}
	while (i < 10)
	{
		test = get_next_line(fd);
		printf("%s", test);
		if (!test)
			break ;
		free (test);
		i++;
	}
	close(fd);
	return (0);
}
