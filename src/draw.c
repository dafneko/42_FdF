/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:42:11 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/17 18:05:08 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_point(t_point *point, int x, int y, t_fdf *fdf)
{
	point->x = x;
	point->y = y;
	point->z = fdf->matrix[y][x].z;
	point->color = fdf->matrix[y][x].color;
	transform(point, fdf);
}

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	cur;
	t_point	next;
	int		next_len;

	y = -1;
	while (++y < fdf->map->height)
	{
		x = 0;
		fdf->len = fdf->matrix[y][x].len;
		if (y + 1 < fdf->map->height)
			next_len = fdf->matrix[y + 1][x].len;
		while (x < fdf->len)
		{
			set_point(&cur, x, y, fdf);
			if (x < fdf->len - 1)
				(set_point(&next, x + 1, y, fdf), draw_line(fdf, &cur, &next));
			if (y < fdf->map->height - 1)
				if (x < next_len)
					(set_point(&next, x, y + 1, fdf), draw_line(fdf, &cur,
							&next));
			x++;
		}
	}
}
