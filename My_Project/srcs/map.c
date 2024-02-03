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
				ft_free_data(data, fd, "Lines with different witdh.");
		}
		data->map_height++;
		free(line);
	}
	close(fd);
}

void	fill_dots(t_pixel *dot, char **line_cleaned, int curr_height)
{
	int		curr_pos;
	char	**z_color;

	curr_pos = 0;
	while (line_cleaned[curr_pos] != 0)
	{
		dot[curr_pos].x = curr_pos;
		dot[curr_pos].y = curr_height;
		z_color = ft_split(line_cleaned[curr_pos], ',');
		dot[curr_pos].z = ft_atoi(z_color[0]);
		if (z_color[1] != 0)
		{
			dot[curr_pos].color = \
			ft_atoi_hex(z_color[1] + 2);
		}
		else
			dot[curr_pos].color = WHITE;
		free(z_color);
		curr_pos++;
	}
}

/*printf("X:%d Y:%d color:%d\n", \
data->map_matrix[curr_height]->x, \
data->map_matrix[curr_height]->y, \
data->map_matrix[curr_height]->color);*/
void	fill_matrix(t_fdf *data, int fd)
{
	char	*line;
	char	**line_cleaned;
	int		curr_height;

	line = get_next_line(fd);
	curr_height = 0;
	data->map_matrix = (t_pixel **)malloc(sizeof(t_pixel *) * data->map_height);
	if (!data->map_matrix)
		ft_free_data(data, fd, "Matrix couldn't be allocated on memory.");
	while (line)
	{
		line = ft_strtrim(line, "\n");
		line_cleaned = ft_split(line, ' ');
		free(line);
		data->map_matrix[curr_height] = \
		(t_pixel *)malloc(sizeof(t_pixel) * data->map_width);
		if (!data->map_matrix[curr_height])
			ft_free_matrix(data, fd, curr_height, \
			"Matrix line couldn't be allocated on memory.");
		fill_dots(data->map_matrix[curr_height], line_cleaned, curr_height);
		curr_height++;
		free(line_cleaned);
		line = get_next_line(fd);
	}
	close(fd);
	//free(line)????
}

void	get_map(t_fdf *data, char *file_name, int fd)
{

	get_map_dimensions(data, fd);
	/*ft_printf("File name = %s | fd: %d\n Height: %d Width: %d\n", \
	file_name, fd, data->map_height, data->map_width);*/
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		ft_free_data(data, fd, "Failed to open the map.");
	fill_matrix(data, fd);
}
