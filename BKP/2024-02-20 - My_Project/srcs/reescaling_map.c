/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reescaling_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:08:24 by uviana-a          #+#    #+#             */
/*   Updated: 2024/02/15 20:08:26 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void centralizing_map(t_pixel *curr_pos, t_pixel *next_pos)
{
    int x_offset;
    int y_offset;

    x_offset = WIDTH * 2 / 5;
    y_offset = HEIGHT * 1 / 5;
    curr_pos->x += x_offset;
    curr_pos->y += y_offset;
    next_pos->x += x_offset;
    next_pos->y += y_offset;
}

static void isometric_scaling(t_pixel *pos)
{
    int x_temp;
    int y_temp;

    x_temp = pos->x;
    y_temp = pos->y;
    pos->x = (x_temp - y_temp) * cos(0.523599);
    pos->y = (x_temp + y_temp) * sin(0.523599) - pos->z;
}

static void diagonal_scaling(t_fdf *data, t_pixel *curr_pos, t_pixel *next_pos)
{
    float   hypotenuse;
    float   scaling_factor;

    hypotenuse = sqrt(data->map_width * data->map_width + \
                        data->map_height * data->map_height);
    scaling_factor = 0.85 * HEIGHT / hypotenuse;
    curr_pos->x = round(curr_pos->x * scaling_factor);
    curr_pos->y = round(curr_pos->y * scaling_factor);
    next_pos->x = round(next_pos->x * scaling_factor);
    next_pos->y = round(next_pos->y * scaling_factor);
}


void    reescaling_map(t_fdf *data, t_pixel *curr_pos, t_pixel *next_pos)
{
    diagonal_scaling(data, curr_pos, next_pos);
    isometric_scaling(curr_pos);
    isometric_scaling(next_pos);
    centralizing_map(curr_pos, next_pos);
}