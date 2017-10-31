/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 03:47:00 by azybert           #+#    #+#             */
/*   Updated: 2017/10/31 12:00:05 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_shell	*initialize_shell(void)
{
	t_shell	*shell;

	if (!(shell = malloc(sizeof(*shell))))
		exit(1);
	if (!(shell->old = malloc(sizeof(*shell->old))))
		exit(1);
	if (!(shell->now = malloc(sizeof(*shell->now))))
		exit(1);
	if (tcgetattr(0, shell->old) == -1)
		exit(-1);
	if (tcgetattr(0, shell->now) == -1)
		exit(-1);
	shell->now->c_lflag &= ~(ICANON);
	shell->now->c_lflag &= ~(ECHO);
	shell->now->c_cc[VMIN] = 0;
	shell->now->c_cc[VTIME] = 1;
	tcsetattr(0, TCSADRAIN, shell->now);
	tputs(tgetstr("vi", NULL), 1, ft_putshit);
	tputs(tgetstr("ti", NULL), 1, ft_putshit);
	return (shell);
}

t_shell			*termanip(void)
{
	static	t_shell *shell = NULL;

	if (shell == NULL)
		shell = initialize_shell();
	else
	{
		tcsetattr(0, TCSADRAIN, shell->old);
		tputs(tgetstr("ve", NULL), 1, ft_putshit);
		tputs(tgetstr("te", NULL), 1, ft_putshit);
		free(shell->old);
		shell->old = NULL;
		free(shell->now);
		shell->now = NULL;
		free(shell);
		shell = NULL;
	}
	return (shell);
}

void			handle_stop(int sig)
{
	if (sig == SIGTSTP)
	{
		termanip();
		signal(SIGINT, SIG_DFL);
		signal(SIGKILL, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
		signal(SIGCONT, handle_stop);
		ioctl(0, TIOCSTI, "\032");
	}
	else if (sig == SIGCONT)
	{
		signal(SIGINT, handle_stop);
		signal(SIGKILL, handle_stop);
		signal(SIGQUIT, handle_stop);
		signal(SIGTSTP, handle_stop);
		termanip();
	}
	else
	{
		termanip();
		exit(1);
	}
}
