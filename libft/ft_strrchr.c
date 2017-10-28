/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 12:45:02 by azybert           #+#    #+#             */
/*   Updated: 2017/01/21 13:49:54 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char *mem;

	mem = (char *)s;
	while (*mem)
		mem++;
	while (s != mem)
	{
		if (*mem == (char)c)
			return (mem);
		mem--;
	}
	if ((char)c == *s)
		return (mem);
	return (NULL);
}
