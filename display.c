/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 01:21:45 by azybert           #+#    #+#             */
/*   Updated: 2017/10/31 12:03:14 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_putshit(int c)
{
	write(0, &c, 1);
	return (0);
}

void		end_display(t_list *list)
{
	int		b;
	t_node	*node;

	b = 1;
	node = list->first;
	while (node != list->first || b == 1)
	{
		b = 0;
		if (node->chosen == 1)
		{
			write(STDOUT_FILENO, node->name, node->length);
			write(STDOUT_FILENO, " ", 1);
		}
		node = node->next;
	}
	del_all(list);
}

static int	loop_display2(t_list *list, t_shell *shell, t_node *loop,
		int mem)
{
	int	space;

	if (((mem + 1) * (list->max_length + 1) - 1) > shell->size_x)
	{
		mem = 0;
		write(0, "\n", 1);
	}
	else
	{
		space = list->max_length - loop->length + 1;
		while (--space >= 0)
			write(0, " ", 1);
	}
	return (mem);
}

void		loop_display(t_list *list, t_shell *shell)
{
	int		b;
	int		mem;
	t_node	*loop;

	tputs(tgetstr("cl", NULL), 1, ft_putshit);
	b = 0;
	mem = 0;
	loop = list->first;
	while (loop != list->first || b == 0)
	{
		if (loop->chosen == 1)
			tputs(tgetstr("mr", NULL), 1, ft_putshit);
		if (loop == list->current)
			tputs(tgetstr("us", NULL), 1, ft_putshit);
		write(0, loop->name, loop->length);
		mem++;
		if (loop->chosen == 1)
			tputs(tgetstr("me", NULL), 1, ft_putshit);
		if (loop == list->current)
			tputs(tgetstr("ue", NULL), 1, ft_putshit);
		if (loop->next != list->first || b == 0)
			mem = loop_display2(list, shell, loop, mem);
		loop = loop->next;
		b = 1;
	}
}
