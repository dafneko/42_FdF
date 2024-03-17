/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:57:32 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/08 05:22:12 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	my_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (!(x > 0 && x < IMG_WIDTH && y > 0 && y < IMG_HEIGHT))
		return ;
	dst = fdf->img_data->addr + (y * fdf->img_data->line_len + x
			* (fdf->img_data->bpp / 8));
	*(unsigned int *)dst = color;
}

t_point	*get_plot(t_point *p1, t_point *p2)
{
	t_point	*plot;

	plot = malloc(sizeof(t_point));
	if (!plot)
		return (NULL);
	if (p1->x < p2->x)
		plot->x = 1;
	else if (p1->x > p2->x)
		plot->x = -1;
	if (p1->y < p2->y)
		plot->y = 1;
	else if (p1->y > p2->y)
		plot->y = -1;
	return (plot);
}

void	get_next_pix(t_point *current_pix, t_point *delta, t_point *plot,
		int error[2])
{
	error[1] = 2 * error[0];
	if (error[1] > delta->y)
	{
		error[0] += delta->y;
		current_pix->x += plot->x;
	}
	if (error[1] < delta->x)
	{
		error[0] += delta->x;
		current_pix->y += plot->y;
	}
}

void	draw_line(t_fdf *fdf, t_point *p1, t_point *p2)
{
	t_point	delta;
	t_point	*plot;
	t_point	current_pix;
	int		error[2];

	current_pix = *p1;
	delta.x = ft_abs(p2->x - p1->x);
	delta.y = -ft_abs(p2->y - p1->y);
	error[0] = delta.x + delta.y;
	plot = get_plot(p1, p2);
	if (!plot)
		return ;
	while (current_pix.x != p2->x || current_pix.y != p2->y)
	{
		my_pixel_put(fdf, current_pix.x, current_pix.y, current_pix.color);
		get_next_pix(&current_pix, &delta, plot, error);
	}
	my_pixel_put(fdf, current_pix.x, current_pix.y, current_pix.color);
	free(plot);
}
