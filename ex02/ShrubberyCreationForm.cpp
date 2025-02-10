/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:45:41 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 16:58:48 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"
#include "./Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getSign())
		throw NotGetSigned();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::ofstream file((target + "_shrubbery"));
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file for writing." << std::endl;
		return;
	}
	file << "                                   @\n"
			"                              @ @ @  @ @ @\n"
			"                            @  @  @ @ /__@\n"
			"                            @@@ @\\ / @/  @ @\n"
			"                           @\\  \\/@| @ | @\n"
			"                          @__\\@ \\ |/ \\| / @\n"
			"                             __\\|@|  ||/__/@\n"
			"                            /  \\ \\\\  / /__\n"
			"                           @    \\  \\/ /   @\n"
			"                                 |\"'|\n"
			"                                 |\"\" |\n"
			"                                 |\"\" |\n"
			"                                ~|\"\"  |~\n"
			"                            ~~~~       ~~~~\n"
			"                          ~~               ~~~" << std::endl;
	file.close();
}
