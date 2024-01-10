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


int close_window(void *param)
{
    (void)param; // Unused parameter
    ft_printf("3) Closing the window.\n");
    exit(0);
}

int main(int argc, char **argv)
{
    //t_fdf   *data;

    check_input_errors(argc, argv[1]);
    /*if (!(mlx = mlx_init()))
    {
        printf("[KO]\n");
        return (1);
    }
    ft_printf("[OK]\n");
    if (!(win1 = mlx_new_window(mlx, 1920, 1080, "Hello_World!")))
    {
        ft_printf("[KO]\n"); //Call a error function.
        return (1);
    }
    ft_printf("[OK]\n");

    //Putting a Pixel on Screen
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);

    //Closing in a dirty way.
    mlx_hook(win1, 17, 0L, close_window, mlx);
    mlx_hook(win1, 2, 1L<<0, close_window, &img);
    
    //Keep the file running.
    mlx_loop(mlx);*/
    return (0);
}
