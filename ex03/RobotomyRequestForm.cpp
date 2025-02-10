/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:24:28 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 17:16:02 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RobotomyRequestForm.hpp"
#include "./Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	static bool robot = true;


	if (!getSign())
		throw NotGetSigned();
	if (executor.getGrade() > getGradeToSign())
		throw GradeTooLowException();

	std::cout << "drilling noises " << std::endl;

	if (robot)
	{
		std::cout << target << " has been robotomized successfully." << std::endl;
		robot = !robot;
	}
	else
	{
		std::cout << "Robotomy failed." << std::endl;
		robot = !robot;
	}
}
