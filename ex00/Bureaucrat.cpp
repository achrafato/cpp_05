/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:36:57 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 14:36:10 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.getName())
{
	this->grade = obj.getGrade();
}

Bureaucrat&Bureaucrat::operator=(const Bureaucrat &c)
{
	if (this != &c)
		this->grade = c.grade;
	return *this;
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
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

ostream &operator<<(ostream &output, const Bureaucrat &f)
{
	output << f.getName() << ", bureaucrat grade " << f.getGrade();
	return output;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
