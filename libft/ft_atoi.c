/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:54:15 by azybert           #+#    #+#             */
/*   Updated: 2017/10/25 07:57:47 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	num;

	num = 0;
	while (ft_isspace(*str))
		str++;
	if ((*str >= '0' && *str <= '9') || *str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			str++;
			while (*str && *str >= '0' && *str <= '9')
				num = num * 10 - (*(str++) - '0');
		}
		else
		{
			if (*str == '+')
				str++;
			while (*str && *str >= '0' && *str <= '9')
				num = num * 10 + (*(str++) - '0');
		}
	}
	return (num);
}
