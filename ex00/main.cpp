/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:37:54 by aibn-che          #+#    #+#             */
/*   Updated: 2024/11/13 14:42:17 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat b("Achraf", 1);

		cout << "Name : " << b.getName() << endl;
		cout << "Grade : " << b.getGrade() << endl;
		cout << b << endl;
		b.incre_Grade();

		cout << "Grade : " << b.getGrade() << endl;
		b.incre_Grade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
	return (0);
}