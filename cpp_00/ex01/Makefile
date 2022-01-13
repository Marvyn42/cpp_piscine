# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 23:29:17 by mamaquig          #+#    #+#              #
#    Updated: 2022/01/11 01:08:27 by mamaquig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phone_bot
SRC			=	$(wildcard *.cpp)
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
