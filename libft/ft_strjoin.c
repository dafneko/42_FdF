/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:49:11 by dkoca             #+#    #+#             */
/*   Updated: 2024/03/08 07:36:04 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = ft_calloc(size, sizeof(char));
	if (!new)
		return (0);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcat(new, s2, size);
	return (new);
}

// int main()
// {
//     char const *s1 = "Hello";
//     char const *s2 = "World!";
//     printf("%s", ft_strjoin(s1, s2));
// }
