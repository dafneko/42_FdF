/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:17:03 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/08 23:17:03 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (0);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}

/*
 #include <stdio.h>
int	main(void)
{
	char const		*s;
	unsigned int	start;
	size_t			len;

	s = "djaskh";
	start = 6;
	len = 20;
	printf("%s", ft_substr(s, start, len));
}
 */
