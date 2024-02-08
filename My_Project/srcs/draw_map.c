/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:54:36 by uviana-a          #+#    #+#             */
/*   Updated: 2024/02/07 19:54:38 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_map(t_fdf *data)
{
    
    ft_printf("Draw_Map.c Height: %d\n", data->map_height);
    
    ft_printf("Let's Find out what's inside our structure :D\n");
	ft_printf("img_ptr		: [%p]\n", data->map_img.img);
	ft_printf("bpp		: [%d]\n", data->map_img.bpp);
	ft_printf("line_len	: [%d]\n", data->map_img.line_lenght);
	ft_printf("endian		: [%d]\n", data->map_img.endian);
	ft_printf("addr		: [%p]\n", data->map_img.addr);
    ft_memcpy(data->map_img.addr, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf", 16*4);
}
