/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:45:46 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/18 23:33:48 by dkoca            ###   ########.fr       */
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

int	check_fd(char *file, t_fdf *fdf)
{
	if (!file)
	{
		free(file);
		return (-1);
	}
	fdf->path = ft_strjoin("./test_maps/", file);
	if (!fdf->path)
		return (-1);
	if (!ft_strchr(fdf->path + 11, '.'))
		return (-1);
	return (0);
}

void	clean_gnl(char *line, int fd)
{
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
