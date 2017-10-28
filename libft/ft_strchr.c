/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:09:03 by azybert           #+#    #+#             */
/*   Updated: 2017/10/25 08:25:28 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*mem;

	mem = (char *)(s - 1);
	while (*(++mem))
		if (*mem == (char)c)
			return (mem);
	if ((char)c == '\0')
		return (mem);
	return (NULL);
}
