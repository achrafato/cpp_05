# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 10:41:02 by aibn-che          #+#    #+#              #
#    Updated: 2024/11/13 17:11:55 by aibn-che         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MSRCS = ./Intern.cpp ./AForm.cpp  ./RobotomyRequestForm.cpp  ./Bureaucrat.cpp  ./ShrubberyCreationForm.cpp ./PresidentialPardonForm.cpp ./main.cpp
MOBJS = $(MSRCS:.cpp=.o)

HEADER = ./Intern.hpp ./AForm.hpp ./PresidentialPardonForm.hpp ./ShrubberyCreationForm.hpp ./Bureaucrat.hpp ./RobotomyRequestForm.hpp

CFLAGS =  -std=c++98 -Wall -Wextra -Werror

NAME =  Intern

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
