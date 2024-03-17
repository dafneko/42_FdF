/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:36:55 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/05 18:36:55 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if ((!dst || !src))
		return (0);
	if (dlen >= size)
		return (slen + size);
	while ((*dst) && --size > 0)
		dst++;
	while ((*src) && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (slen + dlen);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*s = "dnsad3848--";
	char		*d;
	size_t		n;

	d = "aahahah";
	n = 20;
	printf("%zu\n", strlcat(d, s, n));
	printf("%zu", ft_strlcat(d, s,n));
}
*/
