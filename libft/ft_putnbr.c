/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 20:39:20 by azybert           #+#    #+#             */
/*   Updated: 2017/10/25 08:12:17 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	*nbr;

	nbr = ft_itoa(n);
	if (nbr != NULL)
		write(1, nbr, ft_strlen(nbr));
	free(nbr);
}
