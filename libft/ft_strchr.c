/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:44:20 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/05 20:44:20 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	const char	*s = "teste";
// 	int			c;

// 	c = '\0';
// 	//printf("%s", ft_strchr(s, c));
// 	printf("%s", strchr(s, c));

// }
