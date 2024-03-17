/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:23:08 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/17 18:07:38 by dkoca            ###   ########.fr       */
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

int	fill_matrix(t_fdf *fdf, int y, int x)
{
	fdf->matrix[y][x].y = y;
	fdf->matrix[y][x].x = x;
	fdf->matrix[y][x].len = fdf->map->width;
	fdf->matrix[y][x].z = fdf->map->depth;
	fdf->matrix[y][x].color = fdf->map->color;
	return (EXIT_SUCCESS);
}

void	get_values(char **split_line, t_fdf *fdf, int line_count)
{
	int		i;
	char	*color;

	i = -1;
	while (split_line[++i])
	{
		color = ft_strchr(split_line[i], ',');
		if (color)
		{
			color = handle_color(color);
			fdf->map->color = ft_atoi_base(color, HEX_U);
		}
		else
			fdf->map->color = 0xFFFFFF;
		fdf->map->depth = ft_atoi(split_line[i]);
		fill_matrix(fdf, line_count, i);
	}
}

void	read_map(int fd, t_fdf *fdf)
{
	char	**split_line;
	char	*line;
	int		line_count;
	int		i;

	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		split_line = ft_split(line, ' ');
		free(line);
		i = 0;
		while (split_line[i])
			++i;
		fdf->map->width = i;
		if (fdf->map->width != i && fdf->map->height == 1)
			(error_handler(MAP_ERROR), close_mlx(fdf), exit(0));
		fdf->matrix[line_count] = malloc(sizeof(t_point) * i);
		if (!fdf->matrix[line_count])
			(error_handler(ENOMEM), close_mlx(fdf), exit(0));
		get_values(split_line, fdf, line_count);
		free_array(split_line);
		line_count++;
		line = get_next_line(fd);
	}
}

int	parse_map(char *file, t_fdf *fdf)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0 || BUFFER_SIZE < 1)
		(error_handler(MAP_ERROR), close_mlx(fdf), exit(0));
	fdf->map = malloc(sizeof(t_map));
	if (!fdf->map)
		return (-1);
	fdf->map->height = 0;
	fdf->map->width = 0;
	fdf->map->depth = 0;
	get_map_height(file, &fdf->map->height);
	fdf->matrix = (t_point **)malloc(sizeof(t_point *) * fdf->map->height);
	if (!fdf->matrix)
		(error_handler(ENOMEM), close_mlx(fdf), exit(0));
	read_map(fd, fdf);
	close(fd);
	return (EXIT_SUCCESS);
}

// 			y x
// matrix[0][0] = 0 0 5 color
// matrix[0][1] = 0 1 6 color
// matrix[0][2] = 7