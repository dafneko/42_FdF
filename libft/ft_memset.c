/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:34:59 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/03 23:46:24 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		*p = (char)c;
		p++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>

int	main(void)
{
	void	*s;
	int		c;
	size_t	n;

	s = malloc(sizeof(char)*5);
	c = 48;
	n = 5;
	printf("%s", (char *)ft_memset(s, c, n));
	free(s);
}
*/