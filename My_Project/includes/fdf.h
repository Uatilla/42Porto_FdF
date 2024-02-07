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
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>

# define WHITE 0x00FFFFFF
# define WIDTH 1920
# define HEIGHT 1080
# define ESC 65307
typedef struct s_pixel
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_pixel;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		bpp;
	int		line_lenght;
	int		endian;
}		t_img;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_pixel	**map_matrix;
	t_img	map_img;
	int		map_width;
	int		map_height;
}		t_fdf;

/*Error Handling*/
int		check_input_errors(int argc, char *file);
void	ft_error(char *msg);
void	ft_free_data(t_fdf *data, int fd, char *msg);
void	ft_free_matrix(t_fdf *data, int fd, int line, char *msg);

/*Map Reading*/
void	get_map(t_fdf *data, char *file, int fd);

/*Map Drawing*/
void	draw_map(t_fdf *data);
#endif
