/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:20:10 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/05 21:20:10 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen(s);
	if ((char)c == '\0')
	{
		return ((char *)(&s[length]));
	}
	while (s[length - i - 1] && (s + length - i - 1) >= s)
	{
		if (s[length - i - 1] == (char)c)
			return ((char *)&s[length - i - 1]);
		i++;
	}
	return (0);
}

// int main(void)

// {
// 	char *str = "teste";
// 	printf("%p\n", &str[5]);
// 	printf("My strrchr %p\n",ft_strrchr(str, 1024));
// 	printf("Real strrchr %p\n",strrchr(str, 1024));

// }
