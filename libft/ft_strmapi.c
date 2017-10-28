/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:35:10 by azybert           #+#    #+#             */
/*   Updated: 2017/01/27 20:22:39 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static char	*ft_strmapi2(size_t len)
{
	char	*mem;

	mem = malloc(len + 1);
	if (mem == NULL)
		return (NULL);
	return (mem);
}

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*mem;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	mem = (char *)s;
	len = 0;
	while (*mem)
	{
		mem++;
		len++;
	}
	mem = ft_strmapi2(len);
	if (mem == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		*mem = f(i, s[i]);
		mem++;
	}
	*mem = '\0';
	mem = mem - len;
	return (mem);
}
