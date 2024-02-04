/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:30:15 by uviana-a          #+#    #+#             */
/*   Updated: 2024/02/03 15:30:17 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*BACKUP BEFORE SPLIT THE FUNCTION:

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
		data->map_matrix[curr_height] = \
		(t_pixel *)malloc(sizeof(t_pixel) * data->map_width);
		if (!data->map_matrix[curr_height])
			ft_free_matrix(data, fd, curr_height, \
			"Matrix line couldn't be allocated on memory.");
		while (line_cleaned[curr_pos] != 0)
		{
			data->map_matrix[curr_height]->x = curr_pos;
			data->map_matrix[curr_height]->y = curr_height;
			z_color = ft_split(line_cleaned[curr_pos], ',');
			data->map_matrix[curr_height]->z = ft_atoi(z_color[0]);
			if (z_color[1] != 0)
			{
				printf("\t\t\t");
				data->map_matrix[curr_height]->color = \
				ft_atoi_hex(z_color[1] + 2);
			}
			else
				data->map_matrix[curr_height]->color = WHITE;
			printf("[%d][%d]color: %d\n", curr_pos, curr_height, \
			data->map_matrix[curr_height]->color);
			free(z_color);
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

*/

/*int	close_window(t_fdf *win)
{
	if (win)
	{
		mlx_destroy_image(win->mlx_ptr, win->map_img.img);
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
		free(win);
		exit (EXIT_SUCCESS);
	}
	return (0);
}*/


