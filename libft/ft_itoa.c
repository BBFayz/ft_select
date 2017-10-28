/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 20:13:58 by azybert           #+#    #+#             */
/*   Updated: 2017/10/25 07:56:00 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long int	magnitude;
	long int	new_value;
	char		*nbr;
	char		*first;

	if (!(nbr = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	new_value = n;
	if (new_value < 0)
		new_value = new_value * (-1);
	magnitude = 1;
	while (magnitude * 10 <= new_value)
		magnitude = magnitude * 10;
	first = nbr;
	if (n < 0)
		*(nbr++) = '-';
	while (magnitude >= 1)
	{
		*(nbr++) = new_value / magnitude + '0';
		new_value = new_value % magnitude;
		magnitude = magnitude / 10;
	}
	*nbr = '\0';
	return (first);
}
