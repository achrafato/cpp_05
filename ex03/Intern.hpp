/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:20:00 by aibn-che          #+#    #+#             */
/*   Updated: 2024/10/13 16:05:38 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "./AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"

class AForm;

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &obj);
		Intern &operator =(const Intern &c);
		~Intern(void);

		AForm *makeForm(const string &name, const string &target);
};

#endif
