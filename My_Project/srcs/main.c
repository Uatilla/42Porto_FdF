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


int	close_window(void *param)
{
	(void)param;
	ft_printf("3) Closing the window.\n");
	exit(0);
}

/*CONSTRUINDO A ESTRTUTURA TIMG A PARTIR DELA, DEPOIS DIRECIONANDO PARA O POINTER.*/
t_img	new_image(t_fdf data)
{
	t_img	img;

	img.img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	if (img.img == NULL)
		ft_error("Failed to create an image.");
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_lenght, &img.endian);
	img.img_width = WIDTH;
	img.img_height = HEIGHT;
	return(img);
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
	int		i;
	int		j;

	//OPEN THE FILE
	fd = check_input_errors(argc, argv[1]);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
	{
		/*MAYBE I COULD HAVE A FUNCTION CALLED:
		'PREPARE FOR CLOSE' TO FREE MEMORY AND CLOSE THE FILE.*/
		close(fd);
		ft_error("Data structure couldn't be allocated on memory.");
	}
	//GETTING THE MAP IN THE STRUCTURE.
	get_map(data, argv[1], fd);

	//STARTING THE PROGRAM THEN OPENING THE WINDOW
	start_program(data, "fdf");
	if (!data->mlx_ptr || !data->win_ptr)
		return (1);	
	//PUTTING PIXELS ON THE WINDOW
	data->map_img = new_image(*data);

	//PRINTING THE STRUCTURE
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

	/*PUTTING AN IMAGE EVERY MLX LOOP EXECUTION*/
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map_img.img, 0, 0);

	//Closing in a dirty way.
	mlx_hook(data->win_ptr, 17, 0L, close_window, data->mlx_ptr);
	mlx_hook(data->win_ptr, 2, 1L<<0, close_window, &data->map_img);
	//Keep the file running.
	mlx_loop(data->mlx_ptr);
	close(fd);
	close(fd);
	close(fd);
	return (0);
}
