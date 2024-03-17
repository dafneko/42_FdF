/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:18:23 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/03 15:47:06 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

/*
int	main(void)
{
	size_t	n;
	void	*s;

	n = 5;
	s = malloc(sizeof(char) * 5);
	printf("%s", (char *)s);
	ft_bzero(s, n);
	printf("%s", (char *)s);
	printf("%s", (char *)bzero(s, n));
}
*/
