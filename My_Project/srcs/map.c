/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:06:10 by uviana-a          #+#    #+#             */
/*   Updated: 2024/01/12 22:06:13 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_dimensions(t_fdf *data, int fd)
{
	char	*line;
	int		prev_map_width;

	data->map_height = 0;
	data->map_width = 0;
	prev_map_width = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_strtrim(line, "\n");
		if (prev_map_width == 0)
			prev_map_width = ft_count_words(line, ' ');
		else
		{
			data->map_width = ft_count_words(line, ' ');
			if (prev_map_width != data->map_width)
			{
				close(fd);
				ft_error("Lines with different witdh.");
			}
		}
		data->map_height++;
		free(line);
	}
	close(fd);
}

void	get_map(t_fdf *data, char *file_name, int fd)
{
	char    *line;
	char    **line_cleaned;
	int     x;
	int     y;
	//int fed;

	get_map_dimensions(data, fd);
	ft_printf("File name = %s | fd: %d\n Height: %d Width: %d\n", file_name, fd, data->map_height, data->map_width);
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		ft_error("Failed to open the file.");
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		x = 0;
		line = ft_strtrim(line, "\n");
		line_cleaned = ft_split(line, ' ');
		while (line_cleaned[x] != 0)
		{
			ft_printf("%s", line_cleaned[x]);
			/*TAKE THE WORD, APPLY THE SPLIT WITH A COMMA AS SEP
			WEATHER THE SECOND WORD IS NOT 0 REPLACE IT-S VALUE ON 
			THE COLOR FIELD.
			Z IS THE FIRST WORD IN THIS CASE.*/





			x++;
		}
		ft_printf("\n");
		y++;
		free(line);
		free(line_cleaned);
		line = get_next_line(fd);

		
	}
}
