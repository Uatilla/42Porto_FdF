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

/*void	fill_matrix(t_fdf *data, int fd)
{
	char	*line;
	char	*line_to_clean;
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
		line_to_clean = ft_strtrim(line, "\n");
		free(line);
		line_cleaned = ft_split(line_to_clean, ' ');
		free(line_to_clean);
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
}*/

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

/*PREVIOUS TESTS DRAWING THE LINES*/
/*ft_printf("Let's Find out what's inside our structure :D\n");
	ft_printf("img_ptr		: [%p]\n", data->map_img.img);
	ft_printf("bpp		: [%d]\n", data->map_img.bpp);
	ft_printf("line_len	: [%d]\n", data->map_img.line_lenght);
	ft_printf("endian		: [%d]\n", data->map_img.endian);
	ft_printf("addr		: [%p]\n", data->map_img.addr);*/
    //ft_memcpy(data->map_img.addr, "{00{{00{{00{{00{{00{{00{{00{{00{{00{{00{{00{{00{{00{{00{{00{{00{", 16*4);
	//put_pixel_img(data->map_img, 500, 500, 0x00FFFFFF);
