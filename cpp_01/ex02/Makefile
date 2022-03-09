# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 03:23:24 by mamaquig          #+#    #+#              #
#    Updated: 2022/03/01 18:41:12 by mamaquig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	adress
SRC			=	$(wildcard *.cpp)
OBJ			=	$(SRC:$S%.cpp=$O%.o)
DEP			=	$(SRC:$S%.cpp=$D%.d)

S		=	
I		=	./
O		=	obj/
D		=	dep/

CXX			=	c++

CXXFLAGS	+=	-I$I
CXXFLAGS	+=	-Wall -Wextra -Werror -std=c++98

RM			=	/bin/rm -f
RMDIR		=	/bin/rm -Rf

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir -p $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$D:
	@mkdir -p $@

$(DEP): | $D

$(DEP): $D%.d: $S%.cpp
	$(CXX) $(CXXFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	$(RMDIR) $(wildcard $(NAME).dSYM)
	$(RMDIR) $O
	$(RM) $(wildcard $(DEP))
	$(RMDIR) $D

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)
