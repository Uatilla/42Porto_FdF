/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:10:55 by uviana-a          #+#    #+#             */
/*   Updated: 2024/02/14 21:10:58 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_line(t_fdf *data, t_pixel *curr_pos, t_pixel *next_pos)
{
    ft_printf("Inside Draw_Line\n\n\n\n");
    ft_printf("Current\t X:%d \t Next:%d\n", curr_pos->x, next_pos->x);
    ft_printf("Height: %d\n", data->map_height);
}