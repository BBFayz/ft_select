/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:53:01 by azybert           #+#    #+#             */
/*   Updated: 2017/10/27 23:21:00 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <curses.h>
#include <term.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	shit();

typedef struct      s_select
{
	char            *name;
	int             select;
	int             cursor;
	struct s_select *next;
	struct s_select *prev;
}                   t_select;

typedef struct      s_list
{
	void            *content;
	size_t          content_size;
	struct s_list   *next;
}                   t_list;

t_shell *getshell(void)
{
	static t_shell *save = NULL;

	if (save == NULL)
		save = newshell();
	updateshell(save);
	return (save);
}

t_shell *newshell(void)
{
	t_shell *shell;

	shell = (t_shell*)malloc(sizeof(t_shell));
	shell->sz = (struct winsize*)malloc(sizeof(struct winsize));
	ioctl(0, TIOCGWINSZ, shell->sz);
	shell->list = NULL;
	shell->tiosold = (struct termios*)malloc(sizeof(struct termios));
	shell->tios = (struct termios*)malloc(sizeof(struct termios));
	if (tcgetattr(0, shell->tiosold) == -1)
		return (NULL);
	tcgetattr(0, shell->tios);
	shell->tios->c_lflag &= ~(ICANON);
	shell->tios->c_lflag &= ~(ECHO);
	shell->tios->c_cc[VMIN] = 1;
	shell->tios->c_cc[VTIME] = 10;
	selectmodeon(shell);
	return (shell);
}

void    updateshell(t_shell *shell)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	shell->sz->ws_col = w.ws_col;
	shell->sz->ws_row = w.ws_row;
}

int         putintc(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}

typedef struct      s_shell
{
	struct winsize  *sz;
	t_select        *list;
	struct termios  *tiosold;
	struct termios  *tios;
	int             sizemax;
	int             wbl;
}                   t_shell;

void    selectmodeon(t_shell *shell)
{
	tcsetattr(0, TCSADRAIN, shell->tios);
	tputs(tgetstr("vi", NULL), 1, putintc);
	tputs(tgetstr("ti", NULL), 1, putintc);
}

void    selectmodeoff(t_shell *shell)
{
	if (shell->tiosold)
		;
	tcsetattr(0, TCSADRAIN, shell->tiosold);
	tputs(tgetstr("te", NULL), 1, putintc);
	tputs(tgetstr("ve", NULL), 1, putintc);
}

int	 main(int argc, char **argv)
{
	t_shell	shell = NULL;

	selectmodeon(&shell);
	shit();
	selectmodeon(&shell);
}
