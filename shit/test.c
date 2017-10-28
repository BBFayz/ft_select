/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 05:10:21 by azybert           #+#    #+#             */
/*   Updated: 2017/10/27 23:10:55 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include <termios.h>

#include <stdlib.h>

#include <stdio.h>
#include <string.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	shit()
{
	char			*name_term;
	struct termios	term;
	char			c;
	char			*res;

	name_term = getenv("TERM");
	tgetent(NULL, name_term);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ISIG);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	/*struct termios	*non_can;
	non_can = malloc(sizeof(struct termios));
	tcgetattr(0, non_can);
	cfmakeraw(non_can);
	non_can->c_cc[VMIN] = 1;
	non_can->c_cc[VTIME] = 0;
	tcsetattr(1, 0, non_can);
	free (non_can);*/
	while (1)
	{
		read(1, &c, 1);
		if (c == 'c')
		{
			res = tgetstr("cl", NULL);
			tputs(res, 1, (int (*)(int))ft_putchar);
		}
		else if (c == 'd')
		{
			res = tgetstr("cm", NULL);
			printf("%s\n", res);
			tputs(tgoto(res, 2, 5), 1, (int (*)(int))ft_putchar);
		}
		else if (c == 'n')
		{
			res = tgetstr("nd", NULL);
			tputs(res, 1, (int (*)(int))ft_putchar);
			//write(1, res, strlen(res));
		}
		else if (c == 'm')
		{
			res = tgetstr("le", NULL);
			tputs(res, 1, (int (*)(int))ft_putchar);
		}
		else if (c == 'e')
		{
			term.c_lflag = ICANON;
			term.c_lflag = ECHO;
			term.c_lflag = ISIG;
			tcsetattr(0, TCSADRAIN, &term);
			return (0);
		}
		else
			write(1, &c, 1);
	}
}
