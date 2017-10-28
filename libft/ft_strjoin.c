/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:35:50 by azybert           #+#    #+#             */
/*   Updated: 2017/10/27 18:07:10 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *name1, char const *name2)
{
	char	*mem;

	if (!(mem = malloc(sizeof(char) *
					(ft_strlen(name1) + ft_strlen(name2) + 1))))
		return (NULL);
	ft_strcpy(mem, name1);
	ft_strcat(mem, name2);
	return (mem);
}
