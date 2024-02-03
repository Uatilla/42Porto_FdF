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



/*Pendencies:

1) Função de encerramento, para fechar todas as linhas 
da map_matrix, a map_matrix no geral e a data.
2) Free (line) at the end of fill_matrix function? when the line exists but
the map_matrix couldn't be allocated, how to deal?

*/





/*BACKUP BEFORE SPLIT THE FUNCTION FILL_MATRIX:

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


/* BACKUP OF FILL_DOTS BECAUSE IT'S ADDING VALUE ONLY ON THE FIRST *T_DOT ELEMENT

void	fill_dots(t_fdf *data, char **line_cleaned, int curr_height)
{
	int		curr_pos;
	char	**z_color;

	curr_pos = 0;
	while (line_cleaned[curr_pos] != 0)
	{
		data->map_matrix[curr_height]->x = curr_pos;
		data->map_matrix[curr_height]->y = curr_height;
		z_color = ft_split(line_cleaned[curr_pos], ',');
		data->map_matrix[curr_height]->z = ft_atoi(z_color[0]);
		if (z_color[1] != 0)
		{
			data->map_matrix[curr_height]->color = \
			ft_atoi_hex(z_color[1] + 2);
		}
		else
			data->map_matrix[curr_height]->color = WHITE;
		free(z_color);
		curr_pos++;
	}
}
*/

/*RUNNING THE STRUCTURE: ONLY FOR TEST PURPOSES
	i = 0;
	while(data->map_matrix[i] != 0)
	{
		j = 0;
		while (j < data->map_width)
		{
			printf("X:%d Y:%d Z:%d color:%d\n", data->map_matrix[i][j].x, \
			data->map_matrix[i][j].y, data->map_matrix[i][j].z, data->map_matrix[i][j].color);
			j++;
		}
		printf("\n\n");
		i++;
	}
*/
