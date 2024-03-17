/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 05:21:36 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/17 16:55:26 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line(t_fdf *fdf, int x, int y, char *str)
{
	mlx_string_put(fdf->mlx_ptr, fdf->window, x, y, L_PURPLE, str);
}

void	print_num(t_fdf *fdf, int x, int y, int info)
{
	char	*num_str;

	num_str = ft_itoa(info);
	print_line(fdf, x, y, num_str);
	free(num_str);
}

void	print_controls(t_fdf *fdf, int x, int y, int m)
{
	print_line(fdf, MENU_X_MARGIN, y + ++m * 20, "--- CONTROLS ---");
	print_line(fdf, x, y + ++m * 20, "Right Click:      Move");
	print_line(fdf, x, y + ++m * 20, "Scroll Down/+:    Zoom in");
	print_line(fdf, x, y + ++m * 20, "Scroll Up/-:      Zoom out");
	print_line(fdf, x, y + ++m * 20, "Scroll Up:        Zoom out");
	print_line(fdf, x, y + ++m * 20, "W/S/A/D/R/Q/Tab:  Rotate");
	print_line(fdf, x, y + ++m * 20, "I:                Isometric Projection");
	print_line(fdf, x, y + ++m * 20, "P:                Parallel Projection");
	print_line(fdf, x, y + ++m * 20, "Space:            Reset Camera");
}

void	menu_info(t_fdf *fdf)
{
	int	x;
	int	y;
	int	m;

	x = MENU_X_MARGIN;
	y = MENU_Y_MARGIN;
	m = 1;
	print_line(fdf, x, y, "--- MAP INFO ---");
	x -= 50;
	print_line(fdf, x, y + m * 20, "Height:           ");
	print_num(fdf, x + 18 * 6, y + m * 20, fdf->map->height);
	print_line(fdf, x, y + ++m * 20, "Width:            ");
	print_num(fdf, x + 18 * 6, y + m * 20, fdf->map->width);
	print_line(fdf, MENU_X_MARGIN, y + ++m * 20, "--- DETAILS ---");
	print_line(fdf, x, y + ++m * 20, "X Offset:         ");
	print_num(fdf, x + 18 * 6, y + m * 20, fdf->cam->x_offset);
	print_line(fdf, x, y + ++m * 20, "Y Offset:         ");
	print_num(fdf, x + 18 * 6, y + m * 20, fdf->cam->y_offset);
	print_line(fdf, x, y + ++m * 20, "Zoom:             ");
	print_num(fdf, x + 18 * 6, y + m * 20, fdf->cam->theta);
	print_controls(fdf, x, y, m);
}

void	set_menu(t_fdf *fdf)
{
	ft_memset(fdf->menu_data->addr, MENU_COLOR, MENU_HEIGHT * MENU_WIDTH
		* (fdf->menu_data->bpp / 8));
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->window, fdf->menu, 0, 0);
	menu_info(fdf);
}
