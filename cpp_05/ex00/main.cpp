/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:46:05 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/11 01:31:24 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat toto("toto", 150);
		std::cout << toto << std::endl;
		toto.DownGrade();
		std::cout << toto << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException const & e) {
		std::cerr << "error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException const& e) {
		std::cerr << "Error: the grade is too low." << std::endl;
	}
	catch (std::exception const & e) {
		std::cerr << "error: " << e.what() << std::endl;
	}
	std::cout << "Fin de fonction." << std::endl;
	return (EXIT_SUCCESS);
}
