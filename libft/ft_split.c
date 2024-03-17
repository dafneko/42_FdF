/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:27:33 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/11 01:27:33 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **arr, size_t n, char *start, size_t size)
{
	if (!arr)
	{
		return (NULL);
		while (n--)
		{
			free(arr[n]);
			arr[n] = NULL;
		}
		free(arr);
	}
	ft_strlcpy(arr[n], start, size);
	return (arr);
}

static size_t	count_words(char const *s, char c)
{
	size_t	word_count;
	size_t	found;

	word_count = 0;
	found = 0;
	while (*s)
	{
		if (*s != c && found == 0)
		{
			found = 1;
			word_count++;
		}
		else if (*s == c && found == 1)
			found = 0;
		s++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	len;
	size_t	i;
	char	*start;

	if (!s)
		return (0);
	len = (count_words(s, c) + 1);
	array = ft_calloc(len, sizeof(*array));
	if (!array)
		return (0);
	i = -1;
	while (*s && ++i < len)
	{
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		start = (char *)s;
		while (*s != c && *s)
			s++;
		array[i] = ft_calloc((size_t)(s - start + 1), sizeof(**array));
		ft_free(array, i, start, (size_t)(s - start + 1));
	}
	return (array);
}

// #include <stdio.h>
// int main()
// {
//     char **arr;
//     char *s = "hello!";
//     char c = ' ';
// 	int i;
// 	arr = ft_split(s, c);
// 	i = 0;
// 	while (arr[i])
// 	{
// 		if (*arr != NULL)
// 		{
// 			free(arr[i]);
// 			i++;
// 		}
// 		*arr = NULL;
// 	}
// 	free(arr);
// }