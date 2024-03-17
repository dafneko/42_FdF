/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:54:59 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/17 19:17:10 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_mlx(t_fdf *fdf)
{
	if (fdf->img)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img);
	if (fdf->menu)
		mlx_destroy_image(fdf->mlx_ptr, fdf->menu);
	if (fdf->window)
		mlx_destroy_window(fdf->mlx_ptr, fdf->window);
	mlx_destroy_display(fdf->mlx_ptr);
	free_fdf(fdf);
	exit(EXIT_SUCCESS);
}

int	handle_key(int key, t_fdf *fdf)
{
	int	ret;

	ret = 1;
	if (key == XK_Escape)
		ret = close_mlx(fdf);
	if (key == XK_minus)
		fdf->cam->theta -= 1;
	if (key == XK_equal && fdf->cam->theta < fdf->map->width * 500)
		fdf->cam->theta += 1;
	if (key == XK_w || key == XK_d || key == XK_a || key == XK_s || key == XK_e
		|| key == XK_q || key == XK_Tab)
		rotate(key, fdf);
	if (key == XK_i)
		set_projection(key, fdf);
	if (key == XK_p)
		set_projection(key, fdf);
	if (key == XK_space)
		set_cam(fdf);
	return (ret);
}

int	render_next_frame(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	fdf->img_data->addr = mlx_get_data_addr(fdf->img, &fdf->img_data->bpp,
			&fdf->img_data->line_len, &fdf->img_data->endian);
	ft_memset(fdf->img_data->addr, IMG_BG_COLOR, W_HEIGHT * IMG_WIDTH
		* (fdf->img_data->bpp / 8));
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->window, fdf->img, IMG_OFFSET_X,
		0);
	set_menu(fdf);
	draw_map(fdf);
	return (EXIT_SUCCESS);
}

void	call_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->window, 2, 1L << 0, handle_key, fdf);
	mlx_hook(fdf->window, 5, 1L << 3, mouse_release, fdf);
	mlx_hook(fdf->window, 4, 1L << 2, handle_mouse, fdf);
	mlx_hook(fdf->window, 6, 1L << 8, mouse_move, fdf);
	mlx_hook(fdf->window, DestroyNotify, StructureNotifyMask, close_mlx, fdf);
	mlx_loop_hook(fdf->mlx_ptr, render_next_frame, fdf);
}
