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
	int		i;
	int		fd;
	char	*line;

	i = 0;
	file = "elem-col.fdf";
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: the file couldn't be opened!\n");
		return (1);
	}
	line = get_next_line(fd);	
	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
	return (0);
}
