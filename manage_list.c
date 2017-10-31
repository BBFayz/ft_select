/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:32:58 by azybert           #+#    #+#             */
/*   Updated: 2017/10/31 10:54:30 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_node	*get_previous_node(t_node *cur)
{
	t_node	*get_him;

	get_him = cur;
	while (get_him->next != cur)
		get_him = get_him->next;
	return (get_him);
}

t_node	*get_down_node(t_list *list, t_shell *shell)
{
	int		d;
	int		mem;
	int		reste;
	t_node	*node;

	d = (shell->size_x + 1) / (list->max_length + 1);
	mem = d;
	reste = list->nb_elem % d;
	node = list->current;
	while (d-- > 0)
	{
		node = node->next;
		if (node == list->first)
		{
			if (mem - d <= reste)
				d = reste - (mem - d);
			else
				d = d + reste;
		}
	}
	return (node);
}

t_node	*get_up_node(t_list *list, t_shell *shell)
{
	int		d;
	int		mem;
	int		reste;
	t_node	*node;

	d = (shell->size_x + 1) / (list->max_length + 1);
	mem = d;
	reste = list->nb_elem % d;
	node = list->current;
	while (d-- > 0)
	{
		if (node == list->first)
		{
			if (mem - d <= reste)
				d = reste - (mem - d);
			else
				d = d + reste;
		}
		node = get_previous_node(node);
	}
	return (node);
}

void	del_node(t_list *list)
{
	t_node	*to_free;
	t_node	*prev;

	to_free = list->current;
	if (to_free == list->first)
		list->first = list->first->next;
	list->current = list->current->next;
	prev = get_previous_node(to_free);
	prev->next = prev->next->next;
	list->nb_elem--;
	free(to_free);
	to_free = NULL;
	if (list->nb_elem == 0)
	{
		free(list);
		list = NULL;
		termanip();
		exit(0);
	}
}

void	del_all(t_list *list)
{
	t_node	*node;

	node = list->first;
	while (1)
		del_node(list);
}
