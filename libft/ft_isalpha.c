/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:34:11 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/03 15:53:43 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*
int	main(void)
 {
	char c, result;

		c = '*';
	result = ft_isalpha(c);
		printf("The result is %d\n", result);

		c = 'B';
	result = ft_isalpha(c);
		printf("The result is %d\n", result);

		c = '+';
	result = ft_isalpha(c);
		printf("The result is %d\n", result);
	return (0);
 }
 */