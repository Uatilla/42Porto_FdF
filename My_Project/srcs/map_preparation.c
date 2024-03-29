/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_preparation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:06:10 by uviana-a          #+#    #+#             */
/*   Updated: 2024/02/20 20:11:36 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_dimensions(t_fdf *data, int fd)
{
	char	*line;
	char	*line_cleaned;
	int		prev_map_width;
	int		width_error;

	prev_map_width = 0;
	width_error = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_cleaned = ft_strtrim(line, "\n");
		free(line);
		if (prev_map_width == 0)
			prev_map_width = ft_count_words(line_cleaned, ' ');
		else
			width_error = check_width(data, line_cleaned, \
			prev_map_width, width_error);
		data->map_height++;
		free(line_cleaned);
	}
	if (width_error == 1)
		ft_free_data(data, fd, "Lines with different witdh.");
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
		if (z_color[1])
		{
			dot[curr_pos].color = \
			ft_atoi_hex(z_color[1] + 2);
		}
		else
			dot[curr_pos].color = WHITE;
		free_split(z_color);
		curr_pos++;
	}
}

char	**clean_line(char *line)
{
	char	*line_to_clean;
	char	**line_cleaned;

	line_to_clean = ft_strtrim(line, "\n");
	free(line);
	line_cleaned = ft_split(line_to_clean, ' ');
	free(line_to_clean);
	return (line_cleaned);
}

void	fill_matrix(t_fdf *data, int fd)
{
	char	*line;
	char	**line_cleaned;
	int		curr_height;

	curr_height = 0;
	data->map_matrix = (t_pixel **)malloc(sizeof(t_pixel *) * data->map_height);
	if (!data->map_matrix)
		ft_free_data(data, fd, "Matrix couldn't be allocated on memory.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_cleaned = clean_line(line);
		data->map_matrix[curr_height] = \
		(t_pixel *)malloc(sizeof(t_pixel) * data->map_width);
		if (!data->map_matrix[curr_height])
			ft_free_matrix(data, fd, curr_height, \
			"Matrix line couldn't be allocated on memory.");
		fill_dots(data->map_matrix[curr_height], line_cleaned, curr_height);
		curr_height++;
		free_split(line_cleaned);
	}
	close(fd);
}

void	get_map(t_fdf *data, char *file_name, int fd)
{
	get_map_dimensions(data, fd);
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		ft_free_data(data, fd, "Failed to open the map.");
	fill_matrix(data, fd);
}
