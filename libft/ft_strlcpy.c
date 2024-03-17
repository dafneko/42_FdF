/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:22:49 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/04 17:22:49 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slength;

	slength = ft_strlen(src);
	if (!size)
		return (slength);
	size -= 1;
	while ((*src) && size--)
		*dst++ = *src++;
	*dst = '\0';
	return (slength);
}
