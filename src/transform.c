/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 05:35:40 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/17 19:25:58 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(double *x, double *y, t_point *point)
{
	*x = (point->x - point->y) * cos(0.523599);
	*y = (point->x + point->y - point->z) * sin(0.523599);
}

void	x_roll(double *y, double *z, float alpha)
{
	double	y_p;
	double	z_p;

	y_p = *y;
	z_p = *z;
	*y = y_p * cos(alpha) + z_p * sin(alpha);
	*z = -y_p * sin(alpha) + z_p * cos(alpha);
}

void	y_pitch(double *x, double *z, float beta)
{
	double	x_p;
	double	z_p;

	x_p = *x;
	z_p = *z;
	*x = x_p * cos(beta) - z_p * sin(beta);
	*z = x_p * sin(beta) + z_p * cos(beta);
}

void	z_yaw(double *x, double *y, float gamma)
{
	double	x_p;
	double	y_p;

	y_p = *y;
	x_p = *x;
	*x = x_p * cos(gamma) - y_p * sin(gamma);
	*y = x_p * sin(gamma) + y_p * cos(gamma);
}

void	transform(t_point *point, t_fdf *fdf)
{
	double	x_p;
	double	y_p;
	double	z_p;

	x_p = point->x;
	y_p = point->y;
	z_p = point->z;
	z_p *= fdf->cam->theta;
	if (z_p > point->z)
		z_p /= 100;
	if (fdf->cam->projection == ISOMETRIC)
		isometric(&x_p, &y_p, point);
	x_roll(&y_p, &z_p, fdf->cam->alpha);
	y_pitch(&x_p, &z_p, fdf->cam->beta);
	z_yaw(&x_p, &y_p, fdf->cam->gamma);
	x_p *= fdf->cam->theta;
	y_p *= fdf->cam->theta;
	z_p *= fdf->cam->theta;
	y_p += fdf->cam->y_offset;
	x_p += fdf->cam->x_offset;
	point->x = x_p;
	point->y = y_p;
	point->z = z_p;
}
