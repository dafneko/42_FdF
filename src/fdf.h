/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:42:53 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/18 00:07:30 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "definitions.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_camera
{
	int			theta;
	float		alpha;
	float		beta;
	float		gamma;
	int			x_offset;
	int			y_offset;
	double		iso_cos;
	double		iso_sin;
	int			projection;
}				t_cam;

typedef struct s_map
{
	int			height;
	int			width;
	int			depth;
	int			color;
}				t_map;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
	int			len;
}				t_point;

typedef struct s_img_data
{
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			color;
}				t_img_data;

typedef struct s_mouse
{
	t_point		*axis;
	int			click;
}				t_mouse;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*window;
	void		*img;
	void		*menu;
	void		*tmp_img;
	t_img_data	*img_data;
	t_img_data	*menu_data;
	t_map		*map;
	t_point		**matrix;
	t_cam		*cam;
	t_mouse		*right_click;
	int			len;
}				t_fdf;

/*fdf.c*/
int				main(int ac, char **av);
t_fdf			*fdf_init(t_fdf *fdf);
int				menu_init(t_fdf *fdf);
int				img_init(t_fdf *fdf);

/*hooks.c*/
int				close_mlx(t_fdf *fdf);
int				handle_key(int key, t_fdf *d);
int				render_next_frame(t_fdf *fdf);
void			call_hooks(t_fdf *fdf);

/*mousehook.c*/
int				mouse_release(int mouse, int x, int y, t_fdf *fdf);
int				handle_mouse(int mouse, int x, int y, t_fdf *fdf);
int				mouse_move(int x, int y, t_fdf *fdf);

/*bresenham*/
void			my_pixel_put(t_fdf *fdf, int x, int y, int color);
void			draw_line(t_fdf *fdf, t_point *p1, t_point *p2);
t_point			*get_plot(t_point *p1, t_point *p2);
void			get_next_pix(t_point *current_pix, t_point *delta,
					t_point *plot, int error[2]);
/*map*/
int				get_map_height(char *file, int *row);
int				parse_map(char *file, t_fdf *fdf);
void			get_values(char **split_line, t_fdf *fdf, int line_count);
void			read_map(int fd, t_fdf *fdf);
int				fill_matrix(t_fdf *fdf, int y, int x);

/*free*/
int				free_fdf(t_fdf *fdf);
int				free_matrix(t_point **matrix, int y);
int				free_array(char **str);

/*draw*/
void			draw_map(t_fdf *fdf);
void			set_point(t_point *point, int x, int y, t_fdf *fdf);
/*transform*/
void			transform(t_point *point, t_fdf *fdf);
void			isometric(double *x, double *y, t_point *point);
void			x_roll(double *y, double *z, float alpha);
void			y_pitch(double *x, double *z, float beta);
void			z_yaw(double *x, double *y, float gamma);
void			transform(t_point *point, t_fdf *fdf);

/*camera*/
int				cam_init(t_fdf *fdf);
void			set_cam(t_fdf *fdf);
void			set_projection(int key, t_fdf *fdf);
void			rotate(int key, t_fdf *fdf);

/*errors*/
void			error_handler(int err);
int				check_fd(char *file);
char			*handle_color(char *color);

/*menu*/
void			set_menu(t_fdf *fdf);
void			menu_info(t_fdf *fdf);
void			print_controls(t_fdf *fdf, int x, int y, int m);
void			print_num(t_fdf *fdf, int x, int y, int info);
void			print_line(t_fdf *fdf, int x, int y, char *str);
#endif