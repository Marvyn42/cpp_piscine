# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 14:59:29 by mamaquig          #+#    #+#              #
#    Updated: 2022/01/11 00:02:43 by mamaquig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone
SRC			=	megaphone.cpp
OBJ			=	$(SRC:.cpp=.o)
CC			=	c++
HEADER		=	-Iheader
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

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
