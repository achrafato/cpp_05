/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:17:02 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 17:45:40 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class AForm;

class Bureaucrat
{
	private:
		const string name;
		int grade;
	public:
		const string &getName(void) const;
		int		getGrade(void) const;

		Bureaucrat(void);
		Bureaucrat(const string &name, int grade);
		void	incre_Grade();
		void	decre_Grade();

		void	signForm(AForm& form) const;

		void	executeForm(AForm const & form);

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
