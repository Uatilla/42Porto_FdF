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

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	get_map_dimensions(t_fdf *data, int fd)
{
	char	*line;
	int		prev_map_width;
	int		i;

	i = 0;
	data->map_height = 0;
	data->map_width = 0;
	prev_map_width = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		ft_printf("[%d]GMD_GNL call\n", i);
		i++;
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

void	fill_matrix(t_fdf *data, int fd)
{
	char	*line;
	char	**line_cleaned;
	int		curr_height;
	int		i;

	i = 0;
	line = get_next_line(fd);
	ft_printf("[%d]FM_GNL call\n", i);
	i++;
	curr_height = 0;
	//ft_printf("Allocate memory for %d lines\n", data->map_height);
	data->map_matrix = (t_pixel **)malloc(sizeof(t_pixel *) * data->map_height);
	if (!data->map_matrix)
		ft_free_data(data, fd, "Matrix couldn't be allocated on memory.");
	while (line)
	{
		//ft_printf("Line[%d]: %s\n", curr_height, line);
		line = ft_strtrim(line, "\n");
		line_cleaned = ft_split(line, ' ');
		free(line);
		//ft_printf("On line %d, allocate memory for %d positions\n", curr_height, data->map_width);
		data->map_matrix[curr_height] = \
		(t_pixel *)malloc(sizeof(t_pixel) * data->map_width);
		if (!data->map_matrix[curr_height])
			ft_free_matrix(data, fd, curr_height, \
			"Matrix line couldn't be allocated on memory.");
		fill_dots(data->map_matrix[curr_height], line_cleaned, curr_height);
		curr_height++;
		free_split(line_cleaned);
		line = get_next_line(fd);
		ft_printf("[%d]GNL call\n", i);
		i++;
	}
	close(fd);
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
