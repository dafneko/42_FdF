/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:31:49 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/23 19:57:55 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	n;
	int	m;

	n = 0;
	m = 1;
	while ((*nptr == 32) || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			m *= -1;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		n *= 10;
		n = n + (*nptr - 48);
		nptr++;
	}
	n *= m;
	return (n);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*npt = "-1234";

	printf("%d\n", ft_atoi(npt));
	printf("%d\n", atoi(npt));
}
*/
