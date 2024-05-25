/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_preparation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:54:36 by uviana-a          #+#    #+#             */
/*   Updated: 2024/02/20 20:11:12 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	prep_horizon_lines(t_fdf *data, int x, int y)
{
	t_pixel	curr_pos;
	t_pixel	next_pos;

	curr_pos.x = data->map_matrix[y][x].x;
	curr_pos.y = data->map_matrix[y][x].y;
	curr_pos.z = data->map_matrix[y][x].z;
	curr_pos.color = data->map_matrix[y][x].color;
	next_pos.x = data->map_matrix[y][x + 1].x;
	next_pos.y = data->map_matrix[y][x + 1].y;
	next_pos.z = data->map_matrix[y][x + 1].z;
	next_pos.color = data->map_matrix[y][x + 1].color;
	draw_line(data, &curr_pos, &next_pos);
}

static void	prep_vert_lines(t_fdf *data, int x, int y)
{
	t_pixel	curr_pos;
	t_pixel	next_pos;

	curr_pos.x = data->map_matrix[y][x].x;
	curr_pos.y = data->map_matrix[y][x].y;
	curr_pos.z = data->map_matrix[y][x].z;
	curr_pos.color = data->map_matrix[y][x].color;
	next_pos.x = data->map_matrix[y + 1][x].x;
	next_pos.y = data->map_matrix[y + 1][x].y;
	next_pos.z = data->map_matrix[y + 1][x].z;
	next_pos.color = data->map_matrix[y + 1][x].color;
	draw_line(data, &curr_pos, &next_pos);
}

void	draw_map(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (x < data->map_width - 1)
				prep_horizon_lines(data, x, y);
			if (y < data->map_height - 1)
				prep_vert_lines(data, x, y);
			x++;
		}
		y++;
	}
}
