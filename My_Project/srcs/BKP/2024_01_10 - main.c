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

int main()
{
    void    *mlx;
    void    *win1;
    t_data  img;
    int     i;
    int     j;
    int     color;

    ft_printf("MinilibX Test Program!\n");
    ft_printf("Step 1) Initializing the connection:\n");
    if (!(mlx = mlx_init()))
    {
        printf("[KO]\n");
        return (1);
    }
    ft_printf("[OK]\n");
    ft_printf("2) Starting the screen: \t");
    if (!(win1 = mlx_new_window(mlx, 1920, 1080, "Hello_World!")))
    {
        ft_printf("[KO]\n"); //Call a error function.
        return (1);
    }
    ft_printf("[OK]\n");

    //Putting a Pixel on Screen
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
    i = 480;
    j = 270;
    color = 0xFFFFFFFF;
    while (j <= 810)
    {
        while(i <= 1440)
        {
            mlx_pixel_put(mlx, win1,  i, j, color);
            i++;
        }
        color++;
        i = 480;
        j++;
    } 
    
    //Closing in a dirty way.
    mlx_hook(win1, 17, 0L, close_window, mlx);
    mlx_hook(win1, 2, 1L<<0, close_window, &img);
    
    //Keep the file running.
    mlx_loop(mlx);
    return (0);
}
