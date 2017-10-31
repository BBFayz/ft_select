/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 00:09:57 by azybert           #+#    #+#             */
/*   Updated: 2017/10/31 13:53:51 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	check_good_size(t_list *list, t_shell *shell)
{
	struct winsize	w;
	int				x;
	int				y;

	ioctl(0, TIOCGWINSZ, &w);
	x = w.ws_col;
	y = w.ws_row;
	if (x >= list->max_length &&
			(x / (list->max_length + (x / list->max_length - 1))) * y >=
			list->nb_elem)
	{
		shell->size_x = x;
		shell->size_y = y;
		return (1);
	}
	else
		return (-1);
}

static void	react(t_list *list, t_shell *shell, int n, char *buf)
{
	if (n == 3)
	{
		if (buf[2] == 67)
			list->current = list->current->next;
		else if (buf[2] == 68)
			list->current = get_previous_node(list->current);
		else if (buf[2] == 65)
			list->current = get_up_node(list, shell);
		else if (buf[2] == 66)
			list->current = get_down_node(list, shell);
	}
	else if (n == 1)
	{
		if (buf[0] == 32)
		{
			list->current->chosen = (list->current->chosen == 0 ? 1 : 0);
			list->current = list->current->next;
		}
		else if (buf[0] == 127 || buf[0] == 126)
			del_node(list);
		else if (buf[0] == 27)
			del_all(list);
		else if (buf[0] == 10)
			end_display(list);
	}
}

static void	main_loop(t_list *list, t_shell *shell)
{
	int		n;
	char	buf[3];

	while (1)
	{
		while (check_good_size(list, shell) == -1)
			;
		loop_display(list, shell);
		if ((n = read(0, &buf, 3)) > 0)
			react(list, shell, n, buf);
	}
}

static void	ft_signal(void)
{
	signal(SIGTERM, handle_stop);
	signal(SIGINT, handle_stop);
	signal(SIGQUIT, handle_stop);
	signal(SIGTSTP, handle_stop);
}

int			main(int argc, char **argv)
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
	{
		write(2, "Try with more arguments\n", 24);
		return (-1);
	}
	ft_signal();
	list = parsing(argv);
	shell = termanip();
	main_loop(list, shell);
	termanip();
	end_display(list);
	return (0);
}
