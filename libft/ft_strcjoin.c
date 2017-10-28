/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:48:51 by azybert           #+#    #+#             */
/*   Updated: 2017/10/27 18:05:45 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char const *name1, char const *name2, char c)
{
	char	*mem;

	if (!(mem = malloc(sizeof(char) *
					(ft_strlen(name1) + ft_strlen(name2) + 2))))
		return (NULL);
	ft_strcpy(mem, name1);
	ft_strcat(mem, &c);
	ft_strcat(mem, name2);
	return (mem);
}
