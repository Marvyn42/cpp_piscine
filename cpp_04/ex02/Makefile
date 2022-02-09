# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 03:23:24 by mamaquig          #+#    #+#              #
#    Updated: 2022/02/06 17:33:27 by mamaquig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Polymorphism2
SRC			=	$(wildcard *.cpp)
OBJ			=	$(SRC:.cpp=.o)
CC			=	c++
HEADER		=	-Iheader
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(HEADER) -o $@ $(OBJ)

%.o: %.cpp
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
