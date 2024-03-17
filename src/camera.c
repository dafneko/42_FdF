/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 05:42:48 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/17 22:01:04 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	cam_init(t_fdf *fdf)
{
	fdf->cam = malloc(sizeof(t_cam));
	if (!fdf->cam)
		(error_handler(ENOMEM), close_mlx(fdf));
	fdf->cam->projection = ISOMETRIC;
	fdf->right_click = malloc(sizeof(t_mouse));
	if (!fdf->right_click)
		(error_handler(ENOMEM), close_mlx(fdf));
	fdf->right_click->axis = malloc(sizeof(t_point));
	if (!fdf->right_click->axis)
		(error_handler(ENOMEM), close_mlx(fdf));
	fdf->right_click->click = 0;
	return (EXIT_SUCCESS);
}

void	set_cam(t_fdf *fdf)
{
	if (fdf->map->width > 400 || fdf->map->height > 400)
		fdf->cam->theta = 2;
	else if (fdf->map->width > 200 || fdf->map->height > 200)
		fdf->cam->theta = 4;
	else if (fdf->map->width > 100 || fdf->map->height > 100)
		fdf->cam->theta = 8;
	else if (fdf->map->width > 30 || fdf->map->height > 30)
		fdf->cam->theta = 14;
	else
		fdf->cam->theta = 34;
	fdf->cam->projection = ISOMETRIC;
	if (fdf->cam->projection == ISOMETRIC)
	{
		fdf->cam->x_offset = IMG_WIDTH / 2;
		fdf->cam->y_offset = IMG_HEIGHT / 3;
	}
	else
	{
		fdf->cam->x_offset = 10;
		fdf->cam->y_offset = 10;
	}
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
}

void	set_projection(int key, t_fdf *fdf)
{
	if (key == XK_p)
	{
		set_cam(fdf);
		fdf->cam->projection = PARALLEL;
	}
	else if (key == XK_i)
	{
		fdf->cam->projection = ISOMETRIC;
		set_cam(fdf);
	}
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == XK_w)
		fdf->cam->alpha += 0.05;
	if (key == XK_d)
		fdf->cam->beta += 0.05;
	if (key == XK_a)
		fdf->cam->beta -= 0.05;
	if (key == XK_s)
		fdf->cam->alpha -= 0.05;
	if (key == XK_e)
		fdf->cam->gamma += 0.05;
	if (key == XK_q)
		fdf->cam->gamma -= 0.05;
	if (key == XK_Tab)
	{
		fdf->cam->alpha += 0.05;
		fdf->cam->gamma += 0.05;
	}
}
