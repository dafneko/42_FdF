/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:20:53 by dkoca             #+#    #+#             */
/*   Updated: 2024/02/14 17:32:42 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	free((void *)s1);
	return (new);
}

char	*readbuf(char *buf, char *line, int bytesread, int fd)
{
	bytesread = 1;
	while (bytesread > 0 && (!ft_strchr(buf, '\n')))
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread == -1)
			return (NULL);
		buf[bytesread] = '\0';
		line = gnl_strjoin(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_vars	v;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	v.buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!v.buf)
		return (NULL);
	v.line = readbuf(v.buf, v.next, v.br, fd);
	free(v.buf);
	v.buf = NULL;
	if (v.line == NULL)
		return (free(v.next), v.next = NULL, NULL);
	while (v.line[v.len] != '\n' && v.line[v.len] && v.line[v.len + 1] != '\0')
		v.len++;
	if (!v.line[v.len])
		return (free(v.line), v.line = NULL, v.next = NULL, NULL);
	v.next = ft_substr(v.line, v.len + 1, ft_strlen(v.line) - v.len);
	v.line[v.len + 1] = '\0';
	v.len = 0;
	return (v.line);
}

// int	main(void)
// {
// 	const char	*file;
// 	int			newFd;
// 	int			i;
// 	char		*ptr;
//
// 	while (i < 3)
// 	{
// 		ptr = get_next_line(newFd);
// 		printf("OUTPUT = {%s}", ptr);
// 		i++;
// 		free(ptr);
// 	}
// 	close(newFd);
// }
