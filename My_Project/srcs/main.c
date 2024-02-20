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
