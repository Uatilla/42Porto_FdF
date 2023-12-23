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

/*HOW TO COMPILE
cc main.c -I.././mlx -L.././mlx -lmlx -lX11 -lXext -lm
*/
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int close_window(void *param)
{
    (void)param; // Unused parameter
    printf("3) Closing the window.\n");
    exit(0);
}

int main()
{
    void    *mlx;
    void    *win1;

    printf("MinilibX Test Program!\n");
    printf("Step 1) Initializing the connection:\t");
    if (!(mlx = mlx_init()))
    {
        printf("[KO]\n");
        return (1);
    }
    printf("[OK]\n");
    printf("2) Starting the screen: \t");
    if (!(win1 = mlx_new_window(mlx, 300, 300, "Hello_World!")))
    {
        printf("[KO]\n");
        return (1);
    }
    printf("[OK]\n");
   /*   UNDERSTAND WHY IT'S 17 AND 0L ON THE FUNCTION
   MLX_HOOK TO CLOSE O 'X' ON THE WINDOW AND WHERE COULD I FIND 
   THE OTHER NUMBERS PARAMETERS.

   mlx_hook(win1, 17, 0L, close_window, mlx); // 17 is the identifier for the "window close" event
   */
   mlx_loop(mlx);
    return (0);
}
