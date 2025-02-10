/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:05:46 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 17:37:24 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

using std::string;
using std::endl;
using std::cout;

class Bureaucrat;

class AForm
{
	private :
		const string name;
		bool Signed;
		const int gradeToSign;
		const int gradeToExecute;
	public :
		AForm(void);
		AForm(const string &name, int g_Tsign, int g_Texecute);
		AForm(const AForm &obj);
		AForm &operator =(const AForm &c);
		virtual ~AForm(void);

		const string &getName(void) const;
		bool		getSign(void) const;
		int		getGradeToSign(void) const;
		int		getGradeToExecute(void) const;

		virtual void execute(const Bureaucrat& executor) const = 0;

		void	beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public :
				const char*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NotGetSigned : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& output, const AForm& form);

#endif
