/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:37:46 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/17 19:46:23 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

/*window and image*/
# define W_HEIGHT 1000
# define W_WIDTH 1900
# define MENU_WIDTH 300
# define MENU_HEIGHT W_HEIGHT
# define IMG_WIDTH 1600
# define IMG_HEIGHT W_HEIGHT
# define IMG_OFFSET_X MENU_WIDTH
# define MENU_COLOR 0x2b2c28
# define IMG_BG_COLOR 0x1c1c1c
# define MENU_X_MARGIN 80
# define MENU_Y_MARGIN 280

/*colors*/
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define BLUE 0x3a86ff
# define RED 0xff0035
# define GREEN 0x70e000
# define PURPLE 0x8338ec
# define L_PURPLE 0xc77dff

/*utils*/
# define READ_ALL 4096
# define ISOMETRIC 1
# define PARALLEL 2
# define MARGIN 10
# define ISO_ANGLE 0.523599

/*ERRORS*/
# define INIT_ERROR 2
# define MAP_ERROR 3
# define MLX_ERROR 4
# define ENOMEM 5
# define SIZE_ERROR 6

#endif