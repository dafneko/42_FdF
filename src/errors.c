/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:45:46 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/17 00:34:04 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_handler(int err)
{
	if (err == INIT_ERROR)
		ft_putendl_fd("Could not create main struct.", 2);
	else if (err == MAP_ERROR)
		ft_putendl_fd("Map error.", 2);
	else if (err == MLX_ERROR)
		ft_putendl_fd("Could not create MLX.", 2);
	else if (err == ENOMEM)
		ft_putendl_fd("No memory left.", 2);
	else if (err == SIZE_ERROR)
		ft_putendl_fd("Map has no height or width.", 2);
	exit(EXIT_FAILURE);
}

char	*handle_color(char *color)
{
	char	*tmp;

	tmp = color + 2;
	while (*(++tmp))
	{
		if (*tmp > 96 && *tmp < 123)
			*tmp -= 32;
	}
	return (color + 3);
}
