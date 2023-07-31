# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 11:11:35 by fmanzana          #+#    #+#              #
#    Updated: 2023/07/31 11:14:37 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutated_abomination

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =	main.cpp

OBJS = $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Mutated Abomination compiled!"

%.o:		%.cpp
	@$(CC) $(CFLAGS) -c $<

clean:
	@rm -f $(OBJS)

fclean:		clean
	@rm -f $(NAME)
	@echo "Everything cleaned!"

re:			fclean all

.PHONY: all clean fclean re
