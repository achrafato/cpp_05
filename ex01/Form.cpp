/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:27:46 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 15:03:03 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"
#include "./Bureaucrat.hpp"

Form::Form(void):name("Form-0"), Signed(false), gradeToSign(1), gradeToExecute(1)
{}

Form::Form(const string &name, int gradeToSign, int gradeToExecute) \
	: name(name), Signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form(){}

Form::Form(const Form &obj) \
	: name(obj.getName()), Signed(obj.getSign()), gradeToSign(obj.getGradeToSign()), gradeToExecute(obj.getGradeToExecute()) {}

Form&Form::operator=(const Form &c)
{
	if (this != &c)
		this->Signed = c.Signed;
	return *this;
}

const string &Form::getName(void) const
{
	return (this->name);
}

bool Form::getSign(void) const
{
	return (this->Signed);
}

int	Form::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeToSign)
		this->Signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& output, const Form& form)
{
	output << "Form name : " << form.getName() << ", Signed: " << (form.getSign() ? "Yes" : "No")
	<< ", Grade required to sign: " << form.getGradeToSign()
	<< ", Grade required to execute: " << form.getGradeToExecute();
	return (output);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
