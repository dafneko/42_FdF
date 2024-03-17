/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:14:24 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/04 15:14:24 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	s = src;
	d = dest;
	if (!dest && !src)
		return (0);
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

// int main()
// {
//    // const void *src = ((void*)0);
//  //   void *dest = ((void*)0);
//     size_t n = 3;
//  //   printf("%s", (char *)ft_memcpy(dest, src, n));
//     printf("%s", (char *)memcpy(((void*)0), ((void*)0), 3));
// }
