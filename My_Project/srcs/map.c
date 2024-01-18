/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:06:10 by uviana-a          #+#    #+#             */
/*   Updated: 2024/01/12 22:06:13 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static int get_height(char *file_name, int fd)
{
    int height;
    char    *line;

    line = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        height++;
        free(line);
    }
    return (height);
}*/


void get_map(t_fdf *data, char *file_name, int fd)
{
    char    *line;
    char    **line_cleaned;
    int     x;
    int     y;

    data->mapWidth = 10;
    ft_printf("File name = %s | fd: %d\n", file_name, fd);
    
    line = get_next_line(fd);
    y = 0;
    while (line) 
    {
        x = 0;
        //LINE WITHOUT THE \N;
        line = ft_strtrim(line, "\n");
        line_cleaned = ft_split(line, ' ');
        while (line_cleaned[x] != 0)
        {
            ft_printf("x%dy%d%s", x, y, line_cleaned[x]);
            x++;
        }
        ft_printf("\n");
		free(line_cleaned);
        free(line);
        line = get_next_line(fd);
        y++;
    }
    free(line);

//X MUST BE THE SAME VALUE IN ALL LINES.


//HOW TO PUT THE CONTENT OF THIS LINE INTO A STRUCT DIRECTLY?











    /*
    while (i < 15)
	{
		line = get_next_line(fd);
		ft_printf("%s", line);
		if (!line)
			break ;
		free (line);
		i++;
	}*/

    //data->mapHeight = get_height(file_name, fd);
    //ft_printf("Height: %d\n", data->mapHeight);
}