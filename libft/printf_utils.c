/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pritnf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:36:09 by dkoca             #+#    #+#             */
/*   Updated: 2024/02/12 22:39:24 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(char *s)
{
	int	len;

	if (!s)
		return (print_str("(null)"));
	len = 0;
	while (*s)
	{
		print_char(*s);
		len++;
		s++;
	}
	return (len);
}

int	putnbr_base(long long int nb, char *base)
{
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (nb < 0 && base_len == 10)
	{
		count += print_char('-');
		count += putnbr_base(-nb, base);
	}
	else if (nb >= base_len)
	{
		count += putnbr_base(nb / base_len, base);
		count += print_char(base[nb % base_len]);
	}
	else
		count += print_char(base[nb % base_len]);
	return (count);
}

int	print_pointer(uintptr_t ptr, char *base, int flag)
{
	unsigned int	base_len;
	int				count;

	if (!ptr && flag)
		return (print_str("(nil)"));
	base_len = 16;
	count = 0;
	if (flag)
	{
		count += print_str("0x");
		count += print_pointer(ptr, base, 0);
	}
	else if (ptr >= base_len)
	{
		count += print_pointer(ptr / base_len, base, 0);
		count += print_char(base[ptr % base_len]);
	}
	else
		count += print_char(base[ptr % base_len]);
	return (count);
}
