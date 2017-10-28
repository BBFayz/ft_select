/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 00:09:57 by azybert           #+#    #+#             */
/*   Updated: 2017/10/28 07:55:43 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		display(t_list *list)
{
	t_node	*loop;

	loop = list->first;
	while (loop != NULL)
	{
		if (loop->chosen == 1)
			tputs(tgetstr("mr", NULL), 1, ft_putshit);
		if (loop == list->current)
			tputs(tgetstr("us", NULL), 1, ft_putshit);
		ft_putstr(loop->name);
		if (loop->chosen == 1)
			tputs(tgetstr("me", NULL), 1, ft_putshit);
		if (loop == list->current)
			tputs(tgetstr("ue", NULL), 1, ft_putshit);
		loop = loop->next;
		write(1, " ", 1);
	}
}

void	go_loop_this(t_list *list, t_shell *shell)
{
	char c;

	c = '0';

	while (c != 'q')
	{
		tputs(tgetstr("cl", NULL), 1, ft_putshit);
		while (check_good_size(list, shell) == -1)
			;
		display(list);
		read(0, &c, 1);
	}
}

int		main(int argc, char **argv)
{
	char	*name_term;
	t_list	*list;
	t_shell	*shell;

	if ((name_term = getenv("TERM")) == NULL)
	{
		write(2, "Please set the environment variable TERM\n", 41);
		return (-1);
	}
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (argc < 2)
		return (0);
	list = start(argv);
	shell = storeterm();
	go_loop_this(list, shell);
	tcsetattr(0, TCSADRAIN, shell->old);
	tputs(tgetstr("ve", NULL), 1, ft_putshit);
	tputs(tgetstr("te", NULL), 1, ft_putshit);
	return (0);
}
