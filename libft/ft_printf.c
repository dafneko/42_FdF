/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:03:06 by dkoca             #+#    #+#             */
/*   Updated: 2024/02/12 22:38:47 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_check(char format, va_list ap)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(ap, int));
	else if (format == 's')
		count += print_str(va_arg(ap, char *));
	else if (format == 'p')
		count += print_pointer(va_arg(ap, uintptr_t), HEX, 1);
	else if (format == 'd' || format == 'i')
		count += putnbr_base(va_arg(ap, int), DIG);
	else if (format == 'u')
		count += putnbr_base(va_arg(ap, unsigned int), DIG);
	else if (format == 'x')
		count += putnbr_base(va_arg(ap, unsigned int), HEX);
	else if (format == 'X')
		count += putnbr_base(va_arg(ap, unsigned int), HEX_U);
	else if (format == '%')
		count += print_char('%');
	else
		count += print_char(format);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		count;

	count = 0;
	if (!str)
		return (-1);
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			count += type_check(str[1], ptr);
			str++;
		}
		else
			count += print_char(*str);
		str++;
	}
	va_end(ptr);
	return (count);
}

/*
#include <stdio.h>

int main () {
	// ft_printf(0);
	// printf("%i", printf(0));
	printf("%i", ft_printf(0));
	return 0;
}

#include <stdio.h>
int	main(void)
{
	int count = 0;
	int mine = 0;
	char *p = "Hi";
	char *ptr = "";
	printf("Address = %p\n", p);
	mine += ft_printf("this is mine %p\n", p);
	count += printf("this is orig %p\n", p);
	printf("org = %i\n", count);
	mine += ft_printf("this is mine %X %X\n", 1234, -1234);
	count += printf("this is orig %X %X\n", 1234, -1234);
	mine += ft_printf("this is mine %x %x\n", 1234, -1234);
	count += printf("this is orig %x %x\n", 1234, -1234);
	mine += ft_printf("this is mine %p %p\n", ptr, p);
	count += printf("this is orig %p %p\n", ptr, p);
	mine += ft_printf("this is mine %s %s\n", "thy will be done", "42 is the best");
	count += printf("this is orig %s %s\n", "thy will be done", "42 is the best");
	mine += ft_printf("this is mine %i %d\n", 75385782, -88888);
	count += printf("this is orig %i %d\n", 75385782, -88888);
	mine += ft_printf("this is mine %u %u\n", 0001, 1164);
	count += printf("this is orig %u %u\n", 0001, 1164);
	mine += ft_printf("this is mine %c %c\n", 'o', 'g');
	count += printf("this is orig %c %c\n", 'o', 'g');
	mine += ft_printf("this is mine %p %s\n", NULL, ptr);
	count += printf("this is orig %p %s\n", NULL, ptr);
	mine += ft_printf("this is mine %c %%\n", '&');
	count += printf("this is orig %c %%\n", '&');
	mine += ft_printf("this is mine %u %x\n", 2147483647, 2147483647);
	count += printf("this is orig %u %x\n", 2147483647, 2147483647);
	mine += ft_printf("non void pointer w mine %p\n", p);
	count += printf("non void pointer w orig %p\n", p);
	mine += ft_printf("void pointer w mine %p\n", (void *)1234);
	count += printf("void pointer w orig %p\n", (void *)1234);
	printf("mine = %i\n", mine);
	ft_printf("mine = %i\n", mine);
	printf("org = %i\n", count);
}
*/