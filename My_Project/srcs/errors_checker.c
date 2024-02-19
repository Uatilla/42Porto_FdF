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

void	ft_error(char *msg)
{
	ft_printf("ERROR: %s\n", msg);
	exit(EXIT_FAILURE);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_input_errors(int argc, char *file)
{
	int	fd;

	if (argc != 2)
		ft_error("Input invalid!\nTry:\n ./fdf <filename.fdf>");
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		ft_error("Failed to open the file.");
	return (fd);
}

void	ft_free_data(t_fdf *data, int fd, char *msg)
{
	free(data);
	close(fd);
	ft_error(msg);
}

void	ft_free_matrix(t_fdf *data, int fd, int line, char *msg)
{
	while (line >= 0)
	{
		if (data->map_matrix[line])
			free(data->map_matrix[line]);
		line--;
	}
	free(data->map_matrix);
	ft_free_data(data, fd, msg);
}
