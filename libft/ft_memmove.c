/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:44 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/23 20:10:52 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	char const	*s;

	s = (char *)src;
	d = dest;
	if (s == d || n == 0)
		return (dest);
	if (d > s && (s + n) > d)
	{
		s = s + n;
		d = d + n;
		while (n-- > 0)
			*(--d) = *(--s);
	}
	else
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	return (dest);
}

// #include <string.h>
// int main()
// {
//     char    *str = "1234567";
//	int n = 3

//     printf("%s\n", (char *)memmove(str + 1, str, 1));
//     printf("%s\n", (char *)ft_memmove(str + 1, str, 1));
// }
