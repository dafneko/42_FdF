/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:04:29 by dkoca             #+#    #+#             */
/*   Updated: 2024/02/18 21:02:55 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# define HEX "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"
# define DIG "0123456789"


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// part one

int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *nptr);
char				*ft_strdup(const char *s);

// part 2
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);

// printf_utils.c
int	print_char(char c);
int	print_str(char *s);
int	putnbr_base(long long int nb, char *base);
int	print_pointer(uintptr_t ptr, char *base, int flag);
// printf
int	type_check(char format, va_list ap);
int	ft_printf(const char *str, ...);

//new
int ft_abs(int n);
int ft_isspace(int c);
int	ft_atoi_base(const char *nptr, char *base);

//get next line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

typedef struct variables
{
	char	*buf;
	int		br;
	char	*next;
	char	*line;
	int		len;
}			t_vars;

char		*get_next_line(int fd);
char		*readbuf(char *buf, char *line, int bytesread, int fd);
// utils.c
char		*gnl_strjoin(char const *s1, char const *s2);

#endif