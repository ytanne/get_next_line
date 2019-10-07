# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 20:47:43 by yorazaye          #+#    #+#              #
#    Updated: 2019/10/06 23:49:24 by yorazaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

F_C = get_next_line

F_H = $(addsuffix .h, $(F_C))

F_O = $(addsuffix .o, $(F_C))

F_F = $(addsuffix .c, $(F_C))

FLAGS = -Wall -Wextra -Werror -I $(F_H) -L libft -lft -g 

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(F_F) $(FLAGS)

clean:
	rm -f $(F_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
