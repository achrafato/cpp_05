# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 10:41:02 by aibn-che          #+#    #+#              #
#    Updated: 2024/10/13 12:16:18 by aibn-che         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MSRCS = ./AForm.cpp  ./RobotomyRequestForm.cpp  ./Bureaucrat.cpp  ./ShrubberyCreationForm.cpp ./PresidentialPardonForm.cpp ./main.cpp
MOBJS = $(MSRCS:.cpp=.o)

HEADER = ./AForm.hpp ./PresidentialPardonForm.hpp ./ShrubberyCreationForm.hpp ./Bureaucrat.hpp ./RobotomyRequestForm.hpp

CFLAGS =  -std=c++98 -Wall -Wextra -Werror

NAME =  AForm

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
