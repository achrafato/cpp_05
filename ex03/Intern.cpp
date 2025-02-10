/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:34:08 by aibn-che          #+#    #+#             */
/*   Updated: 2024/10/13 17:27:26 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern.hpp"

Intern::Intern(void){}

Intern::~Intern(void){}

Intern &Intern::operator =(const Intern &c) { (void)c; return *this;}

Intern::Intern(const Intern &obj){ (void)obj; }

AForm *Intern::makeForm(const string &name, const string &target)
{
	AForm *form = NULL;
	int i = 0;
	string s[3] = {"Shrubbery", "Robot", "Presidential"};
	while (i < 3)
	{
		if (!name.compare(s[i]))
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break ;
		case 1:
			form = new RobotomyRequestForm(target);
			break ;
		case 2:
			form = new PresidentialPardonForm(target);
			break ;
		default :
			cout << "Form " << name << " doesn't exist !!!!!" << endl;
			return (form);
		cout << "Intern creates " << name << endl;
	}
	return (form);
}
