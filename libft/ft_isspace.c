/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 03:05:01 by dkoca             #+#    #+#             */
/*   Updated: 2024/02/18 03:49:08 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isspace(int c)
{
	if ((c == 32) || (c > 8 && c < 14))
		return (c);
	return (0);	
}