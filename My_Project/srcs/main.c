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

    ft_printf("Since I know my makefile is working!\n\n");
    ft_printf("MinilibX Test Program!\n");
    ft_printf("Step 1) Initializing the connection:\n");
    if (!(mlx = mlx_init()))
    {
        printf("[KO]\n");
        return (1);
    }
    ft_printf("[OK]\n");
    ft_printf("2) Starting the screen: \t");
    if (!(win1 = mlx_new_window(mlx, 300, 300, "Hello_World!")))
    {
        ft_printf("[KO]\n");
        return (1);
    }
    ft_printf("[OK]\n");
    ft_printf("\n\n\n\n%d\n\n\n", ft_strlen("Hello"));
   /*   UNDERSTAND WHY IT'S 17 AND 0L ON THE FUNCTION
   MLX_HOOK TO CLOSE O 'X' ON THE WINDOW AND WHERE COULD I FIND 
   THE OTHER NUMBERS PARAMETERS.

   mlx_hook(win1, 17, 0L, close_window, mlx); // 17 is the identifier for the "window close" event
   */
   mlx_loop(mlx);
    return (0);
}
