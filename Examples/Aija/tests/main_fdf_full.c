/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:54:13 by arepsa            #+#    #+#             */
/*   Updated: 2023/06/20 13:55:29 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(char **map)
{
	int	i;

	i = 0;

	if (map)
	{
		while (map[i])
		{
			printf("%d: %s\n", i, map[i]);
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	ft_error(char *msg)
{
	ft_printf("Error : %s\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_freematrix(t_fdf *data, int i)
{
	
	while (i >= 0)
	{
		if (data->z_matrix[i])
			free(data->z_matrix[i]);
		i--;
	}
	free(data->z_matrix);
	free(data);
}

int		get_height(char *file_name)
{
	int	fd;
	int	height;
	char *line;

	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = NULL;
	if (fd == -1)
        	ft_error("Failed to open the file.");
	while((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	return(height);

}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}



void	split_line(t_dot *matrix, char *line)
{
	char **points;
	int	i;

	points = ft_split(line, ' ');
	i = 0;
	while (points[i])
	{
			matrix[i].z = ft_atoi(points[i]);
			matrix[i].x = 0;
			matrix[i].y = 0;
			if (!ft_strchr(points[i], ','))
					matrix[i].color = WHITE;
			else
			{
				matrix[i].color = ft_atoi_hex(ft_strchr(points[i], ',') + 3);
			}
			i++;
	}
	free_tab(points);
}

void	get_file(t_fdf *data, char *file_name)
{
	int	fd;
	int i;

	i = 0;
	data->height = get_height(file_name);
	data->map = malloc(sizeof(char *) * (data->height + 1));
	fd = open (file_name, O_RDONLY, 0);
	if (fd == -1)
        	ft_error("Failed to open the file.");
	data->map[0] = get_next_line(fd);
	//printf("%i, %s\n", i, data->map[i]);
	while (data->map[i])
	{
		data->map[++i] = get_next_line(fd);
		//printf("%i, %s\n", i, data->map[i]);
	}
	close(fd);
}

void	read_file(t_fdf *data)
{
	int	i;
	int	prev_width;
	int curr_width;

	data->z_matrix = (t_dot **)malloc(sizeof(t_dot *) * (data->height));
	i = 0;
	curr_width = 0;
	prev_width = 0;
	while ((data->map[i]))
	{
		curr_width = ft_count_words(data->map[i]);
        if (prev_width == 0)
            prev_width = curr_width;
		else if (curr_width != prev_width)
        {
			free_map(data->map);
            ft_freematrix(data, i - 1);
            ft_error("Invalid map: Rows have different sizes.");
        }
		data->z_matrix[i] = (t_dot *)malloc(sizeof(t_dot) * (curr_width));
		 if (!data->z_matrix[i])	
		{
            ft_freematrix(data, i);
            ft_error("Memory allocation failed for data->z_matrix[i]");
        }
		split_line(data->z_matrix[i], data->map[i]);
		i++;
	}
	free_tab(data->map);
	data->width = curr_width;
}
	/* 
    while ((line = get_next_line(fd)))
    {
        curr_width = ft_count_words(line);
        if (prev_width == 0)
            prev_width = curr_width;
        else if (curr_width != prev_width)
        {
            ft_freematrix(data, i); 
			free(line); 
            ft_error("Invalid map: Rows have different sizes.");
        }
        data->z_matrix[i] = (t_dot *)malloc(sizeof(t_dot) * (curr_width));
		 if (!data->z_matrix[i])
        {
            ft_freematrix(data, i);
			free(line);
            ft_error("Memory allocation failed for data->z_matrix[i]");
        }
        split_line(data->z_matrix[i], line);
        free(line);
        i++; */


t_img	new_img(t_fdf data)
{
	t_img	img;

	img.img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	if (img.img == NULL)
		ft_error("Failed to create image.");
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
								&img.endian);
	img.width = WIDTH;
	img.height = HEIGHT;
	return (img);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && y >= 0 && x < img->width && y < img->height)
	{
		pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int*)pixel = color;
	}
}

int	get_color(t_dot *a, t_dot *z)
{
	if (a->color != WHITE) 
        return a->color;
    if (z->color != WHITE) 
	{
        return z->color;
	}
	return (WHITE);
}
void	isometric(t_dot *point)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = point->x;
	y_tmp = point->y;
	point->x = (x_tmp - y_tmp) * cos(0.523599);
	point->y = (x_tmp + y_tmp) * sin(0.523599) - point->z;
}

void	scale_map(t_fdf *data, t_dot *a, t_dot *b)
{
	float map_diagonal;
	float factor;
	
	map_diagonal = sqrt(data->width * data->width + data->height * data->height);
	factor = 0.85 * HEIGHT / map_diagonal;
	a->x = round(a->x * factor);
	a->y = round(a->y * factor);
	b->x = round(b->x * factor);
	b->y = round(b->y * factor);
}

void	center_map(t_dot *a, t_dot *b)
{
    int x_offset = WIDTH * 2 / 5;;
    int y_offset = HEIGHT * 1 / 5;

    a->x += x_offset;
    a->y += y_offset;
    b->x += x_offset;
    b->y += y_offset;
}
void	transform_map(t_fdf *data, t_dot *a, t_dot *b)
{
	scale_map(data, a, b);
	isometric(a);
	isometric(b); 
	center_map(a, b);
}

static void	bresenham_define(t_bresenham *param, t_dot *a, t_dot *b)
{
	param->dx = abs(b->x - a->x);
	param->dy = -1 * abs(b->y - a->y);
	if (a->x <= b->x)
		param->sx = 1;
	else
		param->sx = -1;
	if (a->y <= b->y)
		param->sy = 1;
	else
		param->sy = -1;
	param->err = param->dx + param->dy;
	param->x0 = a->x;
	param->y0 = a->y;
}

void draw_line(t_fdf *data, t_dot *a, t_dot *b)
{
	t_bresenham	*param;

	transform_map(data, a, b);
	param = (t_bresenham *)malloc(sizeof(t_bresenham));
	bresenham_define(param, a, b);
	while (1)
	{
		if (param->x0 < WIDTH && param->x0 > 0 && param->y0 < HEIGHT && param->y0 >0)
			put_pixel(&data->img, param->x0, param->y0, get_color(a, b));
		if (param->x0 == b->x && param->y0 == b->y)
			break ;
		param->err2 = 2 * param->err;
		if (param->err2 >= param->dy && param->x0 != b->x)
		{
			param->err += param->dy;
			param->x0 += param->sx;
		}
		if (param->err2 <= param->dx && param->y0 != b->y)
		{
			param->err += param->dx;
			param->y0 += param->sy;
		}
	}
	free(param);
}

void draw_horizontal_lines(t_fdf *data, int x, int y)
{
	t_dot a;
	t_dot b;

	a.x = x;
	a.y = y;
	a.z = data->z_matrix[y][x].z;
	a.color = data->z_matrix[y][x].color;

	b.x = x + 1;
	b.y = y;
	b.z = data->z_matrix[y][x + 1].z;
	b.color = data->z_matrix[y][x + 1].color;

	draw_line(data, &a, &b);
}

void draw_vertical_lines(t_fdf *data, int x, int y)
{
	t_dot a;
	t_dot b;

	a.x = x;
	a.y = y;
	a.z = data->z_matrix[y][x].z;
	a.color = data->z_matrix[y][x].color;

	b.x = x;
	b.y = y + 1;
	b.z = data->z_matrix[y + 1][x].z;
	b.color = data->z_matrix[y + 1][x].color;

	draw_line(data, &a, &b);
}

void draw_map(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw_horizontal_lines(data, x, y);
			if (y < data->height - 1)
				draw_vertical_lines(data, x, y);
			x++;
		}
		free(data->z_matrix[y]);
		y++;
	}
	free(data->z_matrix);
}

t_fdf	new_program(int w, int h, char *str)
{
	t_fdf fdf;

	fdf.mlx_ptr = mlx_init();
	fdf.width = w;
	fdf.height = h;
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIDTH, HEIGHT, str);
	return (fdf);
}
int	exit_window(t_fdf *win)
{
	if (win)
	{
		mlx_destroy_image(win->mlx_ptr, win->img.img);
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
		free(win);
		exit (EXIT_SUCCESS);
	}
	return (0);
}
int	handle_key_event(int key_pressed, void	*param)
{
	t_fdf	*win;

	win = (t_fdf *)param;
	if (key_pressed == ESC || !win)
		exit_window(win);
    return (0);
}

void	handle_input_errors(int argc, char *file)
{
	int	fd;

	if (argc != 2)
	{
		ft_error("Invalid input\nValid input:\n./fdf <filename.fdf>");
	}		
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_error("Failed to open the file");
	}
	else
		close(fd);
}
	
/* void	handle_map_errors(t_fdf *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while(data->z_matrix[i])
	{
		j = 0;
		while(data->z_matrix[i][j])
		{
			j++;
		}
		if(i != 0 && count != j)
		{
			i = data->height;
			ft_freematrix(data, i);
            ft_error("Invalid map: rows of different size.");
		}
		count = j;
		i++;
	}
}  */

int	main(int argc, char **argv)
{
	t_fdf	*data;

	handle_input_errors(argc, argv[1]);
	data = (t_fdf*)malloc(sizeof(t_fdf));
	get_file(data, argv[1]);
	read_file(data);
	//handle_map_errors(data);
	*data = new_program(data->width, data->height, "fdf");
	if (!data->mlx_ptr || !data->win_ptr)
		return (1);
	data->img = new_img(*data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	mlx_hook(data->win_ptr, 17, 0, exit_window, data);
	mlx_key_hook(data->win_ptr, &handle_key_event, data);
	mlx_loop(data->mlx_ptr);
	free(data);
	exit(EXIT_SUCCESS);
	return (0);
}
