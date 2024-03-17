/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:10:31 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/23 19:59:58 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*m;
	size_t			i;

	i = 0;
	m = malloc(count * size);
	if (!m)
		return (0);
	while (i < count * size)
	{
		m[i] = 0;
		i++;
	}
	return (m);
}
