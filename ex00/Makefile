# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 10:41:02 by aibn-che          #+#    #+#              #
#    Updated: 2024/11/11 18:44:11 by aibn-che         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MSRCS = ./Bureaucrat.cpp ./main.cpp
MOBJS = $(MSRCS:.cpp=.o)

HEADER = ./Bureaucrat.hpp

CFLAGS =  -std=c++98 -Wall -Wextra -Werror

NAME =  Bureaucrat

all : $(NAME)

%.o:%.cpp $(HEADER)
	c++ $(CFLAGS) -c $< -o $@

$(NAME): $(MOBJS)
	c++ $(CFLAGS) $^ -o $(NAME)

clean:
	rm -f $(MOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
