/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:37:54 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 16:59:54 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	try
	{
		Bureaucrat bureaucrat("captain", 137);

		ShrubberyCreationForm form1("Shrubbery");
		RobotomyRequestForm form2("Robotomy");
		PresidentialPardonForm form3("President");

		bureaucrat.signForm(form1);
		cout << form1 << endl;
		bureaucrat.executeForm(form1);
		std::cout << "\n" << std::endl;

		bureaucrat.signForm(form2);
		cout << form2 << endl;
		bureaucrat.executeForm(form2);


		std::cout << "\n" << std::endl;

		bureaucrat.signForm(form3);
		cout << form3 << endl;
		bureaucrat.executeForm(form3);

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
