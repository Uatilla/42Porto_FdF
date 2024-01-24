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
	int		x;
	int		y;
	//int		z;
	char	*color;

	line = get_next_line(fd);
	y = 0;
	ft_printf("Height> %d\n\n", data->map_height);
	color = NULL;
	data->map_matrix = (t_pixel **)malloc(sizeof(t_pixel *) * data->map_height);
	if (!data->map_matrix)
		ft_free_data(data, fd, "Matrix couldn't be allocated on memory.");
	while (line)
	{
		x = 0;
		line = ft_strtrim(line, "\n");
		line_cleaned = ft_split(line, ' ');
		data->map_matrix[y] = (t_pixel *)malloc(sizeof(t_pixel) * data->map_width);
		if (!data->map_matrix[y])
			ft_free_matrix(data, fd, y, "Matrix line couldn't be allocated on memory.");
		while (line_cleaned[x] != 0)
		{
			data->map_matrix[y]->x = x;
			data->map_matrix[y]->y = y;
			z_color = ft_split(line_cleaned[x], ',');
			data->map_matrix[y]->z = ft_atoi(z_color[0]); //atributtes z
			if (z_color[1] != 0)
				color = z_color[1]; //atributes color
			ft_printf("color: %s\n", color);
			free(z_color);

			/*Pendencies:
			1. Color on line 57 should be different and I need to attributes it on line
			74.
			2. Rename the x and y variable to don't messup with the structure values.
			2. I need to remove x and y variables and run the loops with the
			structure value.
			3. z variable should be gone.
			
			
			*/





			x++;
		}
		ft_printf("\n\n\n");
		y++;
		free(line);
		free(line_cleaned);
		line = get_next_line(fd);

		
	}
	close(fd);
	//where to close fd?
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
