/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:02:27 by uviana-a          #+#    #+#             */
/*   Updated: 2024/01/10 21:02:30 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_error(char *msg)
{
    ft_printf("ERROR: %s\n", msg);
    exit(EXIT_FAILURE);
}

int    check_input_errors(int argc, char *file)
{
    int fd;

    if (argc != 2)
        ft_error("Input invalid!\nTry:\n ./fdf <filename.fdf>"); 
       
    if((fd = open(file, O_RDONLY, 0)) == -1)
        ft_error("Failed to open the file.");
    /*else
        close(fd);*/
    return (fd);
}
