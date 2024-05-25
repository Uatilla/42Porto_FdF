/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:10:55 by uviana-a          #+#    #+#             */
/*   Updated: 2024/02/20 20:11:04 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && y >= 0 && x < img->img_width && y < img->img_height)
	{
		pixel = img->addr + ((y * img->line_lenght) + (x * (img->bpp / 8)));
		*(unsigned int *) pixel = color;
	}
}

int	choose_color(t_pixel *curr_pos, t_pixel *next_pos)
{
	if (curr_pos->color != WHITE)
		return (curr_pos->color);
	else if (next_pos->color != WHITE)
		return (next_pos->color);
	return (WHITE);
}

static void	bresenham_algorithm(t_bresenham *dot, t_pixel *curr_pos, \
t_pixel *next_pos)
{
	dot->dx = abs(next_pos->x - curr_pos->x);
	dot->dy = -1 * abs(next_pos->y - curr_pos->y);
	if (curr_pos->x <= next_pos->x)
		dot->sx = 1;
	else
		dot->sx = -1;
	if (curr_pos->y <= next_pos->y)
		dot->sy = 1;
	else
		dot->sy = -1;
	dot->err = dot->dx + dot->dy;
	dot->x0 = curr_pos->x;
	dot->y0 = curr_pos->y;
}

void	draw_line(t_fdf *data, t_pixel *curr_pos, t_pixel *next_pos)
{
	t_bresenham	dot;

	reescaling_map(data, curr_pos, next_pos);
	bresenham_algorithm(&dot, curr_pos, next_pos);
	while (1)
	{
		if (dot.x0 < WIDTH && dot.x0 > 0 && dot.y0 < HEIGHT && dot.y0 > 0)
			put_pixel_img(&data->map_img, dot.x0, dot.y0, \
			choose_color(curr_pos, next_pos));
		if (dot.x0 == next_pos->x && dot.y0 == next_pos->y)
			break ;
		if (2 * dot.err >= dot.dy && dot.x0 != next_pos->x)
		{
			dot.err += dot.dy;
			dot.x0 += dot.sx;
		}
		if (2 * dot.err <= dot.dx && dot.y0 != next_pos->y)
		{
			dot.err += dot.dx;
			dot.y0 += dot.sy;
		}
	}
}
