/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 03:47:00 by azybert           #+#    #+#             */
/*   Updated: 2017/10/28 07:31:04 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_shell	*initialize_shell()
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
	shell->now->c_cc[VTIME] = 200;
	tcsetattr(0, TCSADRAIN, shell->now);
	tputs(tgetstr("vi", NULL), 1, ft_putshit);
	tputs(tgetstr("ti", NULL), 1, ft_putshit);
	return (shell);
}

t_shell	*storeterm()
{
	static	t_shell *shell = NULL;

	if (shell == NULL)
		shell = initialize_shell();
	return (shell);
}
