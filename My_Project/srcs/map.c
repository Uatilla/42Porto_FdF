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

void    get_map_dimensions(t_fdf *data, int fd)
{
    
    char    *line;
   // int prev_mapWidth;

    data->mapHeight = 0;
    data->mapWidth = 0;
    //prev_mapWidth = 0;
    line = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        ft_printf("Width: %d\n", ft_count_words(line, ' '));
        //REVIEW COUNT WORDS


        /*
        if (prev_mapWidth == 0)
        {
            prev_mapWidth = ft_count_words(line, ' ');
            ft_printf("IF \n Prev: %d Wid:%d \n", prev_mapWidth, data->mapWidth);
        }
        else
        {
            data->mapWidth = ft_count_words(line, ' ');
            if (prev_mapWidth != data->mapWidth)
            {
                close(fd);
                ft_error("Lines with different witdh.");
            }
            ft_printf("ELSE \n Prev: %d Wid:%d \n", prev_mapWidth, data->mapWidth);
        }*/

        /*CHECK ABOUT THE WIDTH IF IT'S EQUAL TO PREVIOUS
        IF NOT FREE(LINE) AND CALL ERROR
        




        LOOK AT THE READ MAP AIJA FILE.
        






        */
        //DO THE VALIDATION IF THEY ARE EQUAL
        data->mapHeight++;
        free(line);
    }

}


void get_map(t_fdf *data, char *file_name, int fd)
{


    //char    *line;
    //char    **line_cleaned;
    //int     x;
    //int     y;

    get_map_dimensions(data, fd);
    ft_printf("File name = %s | fd: %d\n Height: %d Width: %d", file_name, fd, data->mapHeight, data->mapWidth);
    /*
    line = get_next_line(fd);
    y = 0;
    while (line) 
    {
        //x = 0;
        //LINE WITHOUT THE \N;
        //line = ft_strtrim(line, "\n");
        //line_cleaned = ft_split(line, ' ');

        while (line_cleaned[x] != 0)
        {
            //WORKING ON GET MAP DIMENSIONS

            1) SHOW THIS WORDS SEPARETED (IF THE SECOND EXIST)
            2) Z = WORD[0]
                IF (WORD[1])
                     COLOR = WORD[1]
            3) X =  x;
            
            //ft_printf("x%dy%d[%s]", x, y, line_cleaned[x]);
            x++;
        }
        //4) y = y;
        //ft_printf("\n\n\n\n\n\n\n");
		//free(line_cleaned);
        //free(line);
        //line = get_next_line(fd);
        //y++;
    }
    free(line);*/

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