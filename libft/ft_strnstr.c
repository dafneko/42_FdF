/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:43:36 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/06 20:43:36 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (len > i && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && len > i + j)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}

	/* big + i is the same as return ((char *)&big[i]); and ((char *)(&(*(big
						+ i)))) */

// #include <strings.h>
// #include <string.h>
// int main()
// {
//     const char *big = "aaabcabcd";
//     const char *little = "abcd";
//     size_t n = 9;
//     printf("%s\n", ft_strnstr(big, little, n));
//    // printf("%s\n", strnstr(big, little, n));

// }
