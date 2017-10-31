/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 00:16:48 by azybert           #+#    #+#             */
/*   Updated: 2017/10/31 05:14:36 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/includes/libft.h"

# include <term.h>
# include <curses.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <fcntl.h>

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_node
{
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

t_list  *parsing(char **argv);
t_shell *termanip();
int		ft_putshit(int c);
void	loop_display(t_list *list, t_shell *shell);
t_node  *get_previous_node(t_node *cur);
t_node  *get_up_node(t_list *list, t_shell *shell);
t_node  *get_down_node(t_list *list, t_shell *shell);
void	del_node(t_list *list);
void    del_all(t_list *list);
void	end_display(t_list *list);
void    handle_stop(int sig);

#endif
