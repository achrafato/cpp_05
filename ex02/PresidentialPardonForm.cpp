/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:26:36 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/12 11:34:31 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PresidentialPardonForm.hpp"
#include "./Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getSign())
		throw NotGetSigned();
	if (executor.getGrade() > getGradeToSign())
		throw GradeTooLowException();

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
