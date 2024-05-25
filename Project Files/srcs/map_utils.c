/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:24:51 by uviana-a          #+#    #+#             */
/*   Updated: 2024/02/20 21:24:53 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_width(t_fdf *data, char *line_cleaned, \
	int prev_map_width, int width_error)
{
	data->map_width = ft_count_words(line_cleaned, ' ');
	if (prev_map_width != data->map_width)
		width_error = 1;
	return (width_error);
}
