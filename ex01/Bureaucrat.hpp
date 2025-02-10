/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:17:02 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 17:37:07 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Form;

class Bureaucrat
{
	private:
		const string name;
		int grade;
	public:
		const string &getName(void) const;
		int		getGrade(void) const;

		Bureaucrat(const string &name, int grade);
		Bureaucrat(void);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator =(const Bureaucrat &c);

		void	incre_Grade();
		void	decre_Grade();

		void	signForm(Form& form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

ostream &operator << (ostream &output, const Bureaucrat &f);

#endif
