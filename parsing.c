/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 00:55:37 by azybert           #+#    #+#             */
/*   Updated: 2017/10/31 13:58:32 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_node	*add_node(char *name)
{
	t_node	*new_node;

	if (!(new_node = malloc(sizeof(*new_node))))
		exit(1);
	new_node->name = name;
	new_node->next = NULL;
	new_node->length = ft_strlen(name);
	new_node->chosen = 0;
	return (new_node);
}

t_list			*parsing(char **argv)
{
	int		loop;
	t_node	*node;
	t_list	*list;

	if (!(list = malloc(sizeof(*list))))
		exit(1);
	list->first = add_node(argv[1]);
	node = list->first;
	list->nb_elem = 1;
	list->max_length = list->first->length;
	list->current = node;
	loop = 1;
	while (argv[++loop])
	{
		node->next = add_node(argv[loop]);
		node = node->next;
		list->nb_elem++;
		list->max_length = ((list->max_length >= node->length) ?
				list->max_length : node->length);
	}
	node->next = list->first;
	if (list->max_length == 0)
		exit(1);
	return (list);
}
