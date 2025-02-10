/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:37:54 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 17:28:10 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./Intern.hpp"

int	main()
{
	try
	{
		Bureaucrat b1("b1", 5);
		AForm	*form;
		Intern	i;

		cout << b1 << endl;
		form = i.makeForm("Shrubbery", "target_1");
		if (form)
		{
			cout << *form << endl;
			form->beSigned(b1);
			cout << *form << endl;
			form->execute(b1);
			delete form;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << " "<< e.what() << endl;
	}
	return (0);
}
