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

void	fill_matrix(t_fdf *data, int fd)
{
	char	*line;
	char	**line_cleaned;
	char	**z_color;
	int		curr_pos;
	int		curr_height;

	line = get_next_line(fd);
	curr_height = 0;
	data->map_matrix = (t_pixel **)malloc(sizeof(t_pixel *) * data->map_height);
	if (!data->map_matrix)
		ft_free_data(data, fd, "Matrix couldn't be allocated on memory.");
	while (line)
	{
		curr_pos = 0;
		line = ft_strtrim(line, "\n");
		line_cleaned = ft_split(line, ' ');
		data->map_matrix[curr_height] = (t_pixel *)malloc(sizeof(t_pixel) * data->map_width);
		if (!data->map_matrix[curr_height])
			ft_free_matrix(data, fd, curr_height, "Matrix line couldn't be allocated on memory.");
		while (line_cleaned[curr_pos] != 0)
		{
			data->map_matrix[curr_height]->x = curr_pos;
			data->map_matrix[curr_height]->y = curr_height;
			z_color = ft_split(line_cleaned[curr_pos], ',');
			data->map_matrix[curr_height]->z = ft_atoi(z_color[0]);
			if (z_color[1] != 0)
			{
				printf("VVVVVVVVVVVVVVV\n");
				data->map_matrix[curr_height]->color = ft_atoi_hex(z_color[1] + 2);
			}
			else
				data->map_matrix[curr_height]->color = WHITE;
			printf("[%d][%d]color: %d\n", curr_pos, curr_height, data->map_matrix[curr_height]->color);
			free(z_color);

			/*Pendencies:
			1) Understand the loop and how this printf on line 78 is working.
			2) Run norminette
			3) Break this code into two functions.
			
			
			*/





			curr_pos++;
		}
		printf("\n\n\n");
		curr_height++;
		free(line);
		free(line_cleaned);
		line = get_next_line(fd);

		
	}
	close(fd);
}

void	get_map(t_fdf *data, char *file_name, int fd)
{
	get_map_dimensions(data, fd);
	ft_printf("File name = %s | fd: %d\n Height: %d Width: %d\n", file_name, fd, data->map_height, data->map_width);
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		ft_free_data(data, fd, "Failed to open the map.");
	fill_matrix(data, fd);


}
