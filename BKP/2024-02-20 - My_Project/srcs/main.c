/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:12:55 by uviana-a          #+#    #+#             */
/*   Updated: 2023/12/18 20:12:58 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_fdf *win)
{
	int	line;

	line = win->map_height - 1;
	if (win)
	{
		mlx_destroy_image(win->mlx_ptr, win->map_img.img);
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_display(win->mlx_ptr);
		while (line >= 0)
		{
			if (win->map_matrix[line])
				free(win->map_matrix[line]);
			line--;
		}
		free(win->map_matrix);
		free(win->mlx_ptr);
		free(win);
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int	handle_key_event(int key_pressed, void *param)
{
	t_fdf	*win;

	win = (t_fdf *)param;
	if (key_pressed == ESC || !win)
		close_window(win);
	return (0);
}

t_img	new_image(t_fdf data)
{
	t_img	img;

	img.img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	if (img.img == NULL)
		ft_error("Failed to create the image.");
	img.addr = mlx_get_data_addr(img.img, &img.bpp, \
	&img.line_lenght, &img.endian);
	img.img_width = WIDTH;
	img.img_height = HEIGHT;
	return (img);
}

void	start_program(t_fdf *data, char *str)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, str);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		fd;

	fd = check_input_errors(argc, argv[1]);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
	{
		close(fd);
		ft_error("Data structure couldn't be allocated on memory.");
	}
	ft_memset(data, 0, sizeof(t_fdf));
	get_map(data, argv[1], fd);
	start_program(data, "fdf");
	if (!data->mlx_ptr || !data->win_ptr)
		return (1);
	data->map_img = new_image(*data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->map_img.img, 0, 0);
	mlx_hook(data->win_ptr, 17, 0L, close_window, data);
	mlx_key_hook(data->win_ptr, &handle_key_event, data);
	mlx_loop(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}
