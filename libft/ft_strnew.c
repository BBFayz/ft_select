/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:54:39 by azybert           #+#    #+#             */
/*   Updated: 2017/01/21 15:53:16 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char *mem;
	char *tmp;

	mem = (char *)malloc(size + 1);
	if (mem == NULL)
		return (NULL);
	tmp = mem;
	while (size--)
	{
		*tmp = '\0';
		tmp++;
	}
	*tmp = '\0';
	return (mem);
}
