/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 20:00:26 by azybert           #+#    #+#             */
/*   Updated: 2017/08/11 05:12:59 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static unsigned int	ft_strlcat2(char *src)
{
	unsigned int	k;
	char			*mem;

	mem = src;
	k = 0;
	while (*mem)
	{
		k++;
		mem++;
	}
	return (k);
}

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			s1_end;
	unsigned int	k;

	if (size == 0)
		return (size + ft_strlcat2((char *)src));
	i = 0;
	k = ft_strlcat2((char *)src);
	while (dst[i] && i < size)
		i++;
	s1_end = i;
	while (src[i - s1_end] && i < size - 1)
	{
		dst[i] = src[i - s1_end];
		i++;
	}
	if (s1_end < size)
		dst[i] = '\0';
	return (s1_end + k);
}
