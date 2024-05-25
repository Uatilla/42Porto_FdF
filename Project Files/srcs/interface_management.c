/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:56:31 by uviana-a          #+#    #+#             */
/*   Updated: 2024/02/20 20:11:27 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_program(t_fdf *data, char *str)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, str);
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
