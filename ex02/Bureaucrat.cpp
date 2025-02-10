/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:36:57 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 17:15:12 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"
#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const string &name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

const string &Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::incre_Grade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decre_Grade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

ostream &operator<<(ostream &output, const Bureaucrat &f)
{
	output << f.getName() << ", bureaucrat grade " << f.getGrade();
	return output;
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		cout << this->name << " signed " << form.getName() << endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		cout << this->getName() << " executed " << form.getName() << endl;
	}
	catch (const std::exception &e)
	{
		cout << "The Bureaucrat " << this->getName() << " failed to execute "<< form.getName()<< " because : " << e.what() << endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
