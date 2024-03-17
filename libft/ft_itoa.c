/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:20:01 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/23 20:06:38 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	numlen(int n)
{
	int	len;

	len = 1; 
	if (n == -2147483648)
		return (12);
	if (n == 0)
	{
		return (len + 1);
	}
	if (n < 0)
	{
		n = -n;
		len += 1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = numlen(n);
	num = (char *)ft_calloc(len, sizeof(char));
	if (!num)
		return (0);
	else if (n < 0)
	{
		num[0] = '-';
		n = -n;
	}
	len -= 1;
	while (len > 0 && num[--len] != '-')
	{
		num[len] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

// int main()
// {
// 	printf("%s", ft_itoa(-1234));
// }
