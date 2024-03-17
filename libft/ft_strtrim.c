/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:43:00 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/10 00:43:00 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (!s1)
	{
		return (0);
	}
	n = ft_strlen(s1) - 1;
	if (!set)
		return ((char *)s1);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[n]))
		n--;
	return (ft_substr(s1, i, n - (i - 1)));
}

/*
int	main(void)
{
	char const	*s1;
	char const	*set;

	s1 = "**Hello**";
	set = "+-* ";
	printf("%s", ft_strtrim(s1, set));
}
 */
