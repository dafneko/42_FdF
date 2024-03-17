/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:10:23 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/08 23:10:23 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*m;

	m = (char *)malloc(ft_strlen(s) + 1);
	if (!m)
		return (0);
	ft_strlcpy(m, s, ft_strlen(s) + 1);
	return (m);
}
