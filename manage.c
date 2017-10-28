/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 07:54:46 by azybert           #+#    #+#             */
/*   Updated: 2017/10/28 08:15:04 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_putshit(int c)
{
	write(1, &c, 1);
	return (0);
}

int	check_good_size(t_list *list, t_shell *shell)
{
	int x;
	int y;

	x = tgetnum("co");
	y = tgetnum("li");
	if (x >= max_length)
	{
		if (x / max_length >= nb_elem)
		{
			shell->size_x = x;
			shell->size_y = y;
			return (1);
		}
	}
	else
		return (-1);
}
