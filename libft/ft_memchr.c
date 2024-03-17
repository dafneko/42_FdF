/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:31:22 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/06 19:31:22 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	unsigned char		chr;

	chr = c;
	str = s;
	while (n > 0)
	{
		if (*str == (unsigned char)chr)
			return ((unsigned char *)str);
		str++;
		n--;
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
//     const void *s = "/|\x12\xff\x09\x42\2002\42|\\";
//     int c = '\200';
//     size_t n = 10;
//     printf("%s\n", (char *)ft_memchr(s, c, n));
//     printf("%s\n", (char *)memchr(s, c, n));
// }
