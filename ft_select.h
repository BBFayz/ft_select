/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 00:16:48 by azybert           #+#    #+#             */
/*   Updated: 2017/10/28 08:15:11 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/includes/libft.h"

# include <term.h>
# include <curses.h>
# include <termios.h>

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_node
{
	int				posx;
	int 			posy;
	int				chosen;
	int				length;
	char			*name;
	struct s_node	*next;
}				t_node;

typedef struct	s_list
{
	struct s_node	*first;
	struct s_node	*current;
	int				nb_elem;
	int				max_length;
}				t_list;

typedef struct	s_shell
{
	struct termios	*old;
	struct termios	*now;
	int				size_x;
	int				size_y;
}				t_shell;

t_node	*add_node(char *name);
t_list  *start(char **argv);
t_shell *storeterm();
int		ft_putshit(int c);
int		check_good_size(t_list *list, t_shell *shell);

#endif
