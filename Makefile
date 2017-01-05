# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 14:43:47 by eleclet           #+#    #+#              #
#*   Updated: 2017/01/03 17:21:03 by eleclet          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = sh
CFLAGS = -Werror -Wall -Wextra -g

SRC = main.c error.c termcaps.c get_term_size.c string_man.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	gcc $(OBJ)  $(CFLAGS) -ltermcap -Llibft -lft -o $(NAME)
	@echo "$(NAME) built"

%.o: %.c
	gcc -c $(CFLAGS) $<

clean :
	rm -rf $(OBJ)
	@make -C libft/ clean
fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean
re : fclean all
