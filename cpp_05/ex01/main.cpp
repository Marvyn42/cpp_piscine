/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:46:05 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/11 04:00:23 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	Bureaucrat toto("toto");
	std::cout << toto << std::endl;
	Form form1("form1");
	Form form2("form2", 1, 10);
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	toto.signForm(form1);
	std::cout << form1 << std::endl;
	toto.signForm(form2);
	std::cout << form2 << std::endl;
	try {
		Form form3("err", 150, 151);
	}
	catch (std::exception const & e) {
		std::cerr << "error: " << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}
