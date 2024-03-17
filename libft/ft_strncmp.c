/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:44:49 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/05 21:44:49 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n || n < 0)
		return (0);
	while (--n > 0 && (*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     const char *s1 = "1234";
//     const char *s2 = "1235";
//     size_t size = -1;
//     printf("%i\n", ft_strncmp(s1, s2, size));
//     printf("%i\n", strncmp(s1, s2, size));
// }
