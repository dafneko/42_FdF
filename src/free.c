/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:33:13 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/17 00:23:30 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_matrix(t_point **matrix, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (EXIT_SUCCESS);
}

int	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (1);
}

int	free_fdf(t_fdf *fdf)
{
	if (fdf->matrix)
		free_matrix(fdf->matrix, fdf->map->height);
	if (fdf->map)
		free(fdf->map);
	if (fdf->cam)
	{
		free(fdf->right_click->axis);
		free(fdf->right_click);
		free(fdf->cam);
	}
	if (fdf->menu)
		free(fdf->menu_data);
	if (fdf->img)
		free(fdf->img_data);
	free(fdf->mlx_ptr);
	free(fdf);
	return (EXIT_SUCCESS);
}
