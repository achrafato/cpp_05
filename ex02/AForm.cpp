/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:27:46 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 16:46:24 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"
#include "./Bureaucrat.hpp"

AForm::AForm(void):name("Form-0"), Signed(false), gradeToSign(1), gradeToExecute(1)
{}

AForm::AForm(const string &name, int gradeToSign, int gradeToExecute):name(name), Signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm(){}

AForm::AForm(const AForm &obj): name(obj.getName()), Signed(obj.getSign()), gradeToSign(obj.getGradeToSign()), gradeToExecute(obj.getGradeToExecute())
{
}

AForm&AForm::operator=(const AForm &c)
{
	if (this != &c)
	{
		this->Signed = c.Signed;
	}
	return *this;
}

const string &AForm::getName(void) const
{
	return (this->name);
}

bool AForm::getSign(void) const
{
	return (this->Signed);
}

int	AForm::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeToSign)
		this->Signed = true;
	else
	 	throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& output, const AForm& form)
{
	output << "Form name : " << form.getName() << ", Signed: " << (form.getSign() ? "Yes" : "No")
	<< ", Grade required to sign: " << form.getGradeToSign()
	<< ", Grade required to execute: " << form.getGradeToExecute();

	return (output);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

const char *AForm::NotGetSigned::what() const throw()
{
	return "Form not get signed yet";
}
