/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:43:49 by uviana-a          #+#    #+#             */
/*   Updated: 2023/12/28 20:43:54 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libraries/mlx/mlx.h"
# include "../libraries/ft_printf/ft_printf.h"
# include "../libraries/libft/libft.h"
# include "../libraries/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>



typedef struct s_pixel
{
    int     x;
    int     y;
    int     z;
    int     color;
}           t_pixel;

typedef struct s_img {
    void    *img;
    char    *addr;
    int     imgWidth;
    int     imgHeight;
    int     bpp;
    int     lineLenght;
    int     endian;
}           t_img;


typedef struct s_fdf
{
    int     mapWidth;
    int     mapHeight;
    char    **mapFile;
    t_pixel **mapMatrix;
    void    *mlxPtr;
    void    *winPtr;
    t_img   mapImg;
}           t_fdf;

//ERROR FUNCTIONS
void    check_input_errors(int argc, char *file);
#endif
