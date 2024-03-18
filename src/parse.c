/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:14:42 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/19 00:16:17 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_height(char *file, int *row)
{
	int		fd;
	int		bytesread;
	int		size;
	char	buf[BUFFER_SIZE + 1];
	int		i;

	fd = open(file, O_RDONLY);
	size = 0;
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread == -1)
			return (-1);
		i = -1;
		while (++i < bytesread)
			if (buf[i] == '\n')
				(*row)++;
		size += bytesread;
	}
	close(fd);
	return (size);
}

char	**get_width(int *i, char **line, t_fdf *fdf)
{
	char	**split_line;

	split_line = ft_split(*line, ' ');
	(free(*line), *line = NULL);
	*i = 0;
	while (split_line[*i])
		++(*i);
	fdf->map->width = *i;
	if (fdf->map->width != *i && fdf->map->height == 1)
		(error_handler(MAP_ERROR), close_mlx(fdf));
	return (split_line);
}
