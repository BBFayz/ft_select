# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azybert <azybert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 02:39:21 by azybert           #+#    #+#              #
#    Updated: 2017/10/28 08:15:08 by azybert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
FILES = ft_select.c list.c term.c manage.c
OBJ = $(FILES:.c=.o)
TERMLIB = -ltermcap
LIBFT = libft/libft.a
CC = GCC
FLAG = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	@(cd libft && make)
	$(CC) -c $(FLAG) $(FILES)
	$(CC) -o $(NAME) $(TERMLIB) $(OBJ) $(LIBFT)

clean:
	@(cd libft && make clean)
	rm -f $(OBJ)

fclean: clean
	@(cd libft && make fclean)
	rm -f $(NAME)

re: fclean all
