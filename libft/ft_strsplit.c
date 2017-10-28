/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:46:36 by azybert           #+#    #+#             */
/*   Updated: 2017/01/29 15:51:48 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**ft_strsplit5(char **tab, char const *s, char c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == c)
			while (*tmp == c)
				tmp++;
		if (*tmp && *tmp != c)
		{
			j = 0;
			while (*tmp && *tmp != c)
			{
				tab[i][j] = *tmp;
				tmp++;
				j++;
			}
			tab[i][j] = '\0';
			i++;
		}
	}
	return (tab);
}

static char	**ft_strsplit4(int i, int *j)
{
	int		k;
	char	**tab;
	int		s;

	s = 0;
	k = -1;
	while (++k < i)
		s = s + j[k];
	tab = (char **)malloc((i + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[i] = NULL;
	k = -1;
	while (++k < i)
	{
		s = j[k];
		tab[k] = (char *)malloc(s + 1);
		if (tab[k] == NULL)
			return (NULL);
	}
	return (tab);
}

static int	*ft_strsplit3(char const *s, char c, int i)
{
	char	*mem;
	int		*j;
	int		l;

	j = (int *)malloc(sizeof(int) * i);
	if (j == NULL)
		return (NULL);
	l = -1;
	mem = (char *)s;
	while (*mem)
	{
		if (*mem == c)
			while (*mem == c)
				mem++;
		if (*mem && *mem != c)
		{
			j[++l] = 0;
			while (*mem && *mem != c)
			{
				mem++;
				j[l] = j[l] + 1;
			}
		}
	}
	return (j);
}

static int	ft_strsplit2(char const *s, char c)
{
	char	*mem;
	int		i;

	i = 0;
	mem = (char *)s;
	while (*mem)
	{
		if (*mem == c)
			while (*mem == c)
				mem++;
		if (*mem && *mem != c)
		{
			while (*mem && *mem != c)
				mem++;
			i++;
		}
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		*j;
	char	**tab;

	if (s == NULL)
		return (NULL);
	i = ft_strsplit2(s, c);
	j = ft_strsplit3(s, c, i);
	if (j == NULL)
		return (NULL);
	tab = ft_strsplit4(i, j);
	if (tab == NULL)
		return (NULL);
	tab = ft_strsplit5(tab, s, c);
	free(j);
	return (tab);
}
