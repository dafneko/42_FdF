/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 02:27:11 by dkoca             #+#    #+#             */
/*   Updated: 2024/02/19 00:30:39 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int is_valid_base(char *base)
{
	int n;
	int i;
	
	n = 0;
	while (base[n])
	{
		if (base[n] == '+' || base[n]== '-')
			return(0);
		if (ft_isspace(base[n]))
			return (0);
		i = n + 1;
		while (base[i])
			if (base[n] == base[i++])
				return (0);
		n++;
	}
	if (n <= 1)
		return (0);
	return(n);
}

static int	get_nb(char c, char *base)
{
	int i;

	i = 0;
	while(base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *nptr, char *base)
{
	int	n;
	int	m;
	int val;

	n = 0;
	m = 1;
	if (is_valid_base(base))
	{
		while ((*nptr == 32) || (*nptr > 8 && *nptr < 14))
			nptr++;
		if (*nptr == '-' || *nptr == '+')
		{
			if (*nptr == '-')
				m *= -1;
			nptr++;
		}
		while (*nptr)
		{
			val = get_nb(*nptr++, base);
			if (val < 0)
				return (n * m);
			n = n * is_valid_base(base) + val;				
		}
	}
	return (n * m);
}

// #include <stdio.h>
// int main()
// {
// 	printf("atoi = %i\n\n", ft_atoi_base("00FFFFFF", "0123456789abcdef"));
	
// }