/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 00:55:37 by azybert           #+#    #+#             */
/*   Updated: 2017/10/28 07:32:19 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_node	*add_node(char *name)
{
	t_node	*new_node;

	if (!(new_node = malloc(sizeof(*new_node))))
		exit(0);
	new_node->name = name;
	new_node->next = NULL;
	new_node->length = ft_strlen(name);
	new_node->chosen = 0;
	return(new_node);
}

t_list  *start(char **argv)
{
	int     loop;
	t_node  *node;
	t_list  *list;

	if (!(list = malloc(sizeof(*list))))
		exit(1);
	if (!(node = malloc(sizeof(*node))))
		exit(1);
	node->name = argv[1];
	node->next = NULL;
	node->chosen = 0;
	list->first = node;
	list->nb_elem = 1;
	list->max_length = ft_strlen(argv[1]);
	list->current = node;
	loop = 1;
	while (argv[++loop])
	{
		node->next = add_node(argv[loop]);
		node = node->next;
		list->nb_elem++;
		list->max_length = ((list->max_length >= node->length) ? list->max_length : node->length);
	}
	return (list);
}
