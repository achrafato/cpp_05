/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:37:54 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 15:17:21 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int	main()
{
	try
	{
		Bureaucrat b2("Achraf", 3);

		Form f1("Form1", 3, 4);
		cout << f1 <<  endl;
		f1.beSigned(b2);
		cout << f1 <<  endl;

		b2.signForm(f1);

		cout << "************************" << endl;

		Form f2("Form2", 2, 2);
		cout << f2 <<  endl;
		f2.beSigned(b2);
		cout << f2 <<  endl;

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << endl;
	}

	return (0);
}
