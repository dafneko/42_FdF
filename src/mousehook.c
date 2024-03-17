/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 04:56:43 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/17 16:56:03 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_release(int mouse, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (mouse == 2)
		fdf->right_click->click = 0;
	return (EXIT_SUCCESS);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	if (x > W_WIDTH || x < 0 || y > W_HEIGHT || y < 0)
		return (0);
	if (fdf->right_click->click)
	{
		fdf->cam->x_offset -= fdf->right_click->axis->x - x;
		fdf->cam->y_offset -= fdf->right_click->axis->y - y;
		fdf->right_click->axis->x = x;
		fdf->right_click->axis->y = y;
	}
	return (EXIT_SUCCESS);
}

int	handle_mouse(int mouse, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (mouse == 5 && fdf->cam->theta < fdf->map->width * 5)
		fdf->cam->theta += 1;
	if (mouse == 4 && fdf->cam->theta > 1)
		fdf->cam->theta -= 1;
	if (mouse == 1)
	{
		fdf->right_click->click = 1;
		fdf->right_click->axis->x = x;
		fdf->right_click->axis->y = y;
	}
	return (EXIT_SUCCESS);
}
