/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:05:46 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/11 21:29:34 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

using std::string;
using std::endl;
using std::cout;

class Bureaucrat;

class Form
{
	private :
		const string name;
		bool Signed;
		const int gradeToSign;
		const int gradeToExecute;
	public :
		Form(void);
		Form(const string &name, int g_Tsign, int g_Texecute);
		~Form();
		Form(const Form &obj);
		Form &operator =(const Form &c);

		const string &getName(void) const;
		bool		getSign(void) const;
		int		getGradeToSign(void) const;
		int		getGradeToExecute(void) const;

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

};
	std::ostream& operator<<(std::ostream& output, const Form& form);
#endif
