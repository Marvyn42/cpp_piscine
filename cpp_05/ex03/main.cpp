/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:46:05 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/11 17:12:45 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {
	AForm* form1;
	AForm* form2;
	AForm* form3;
	AForm* form_err;
	Intern intern;
	Bureaucrat bureaucrat("bureaucrat", MAX_GRADE);

	form1 = intern.makeForm("ShrubberyCreation", "MyGarden");
	if (form1) {
		bureaucrat.signForm(*form1);
		bureaucrat.executeForm(*form1);
	}

	std::cout << std::endl;

	form2 = intern.makeForm("RobotomyRequest", "Antoine");
	if (form2) {
		bureaucrat.signForm(*form2);
		bureaucrat.executeForm(*form2);
	}

	std::cout << std::endl;

	form3 = intern.makeForm("PresidentialPardon", "Norminet");
	if (form3) {
		bureaucrat.signForm(*form3);
		bureaucrat.executeForm(*form3);
	}

	std::cout << std::endl;

	form_err = intern.makeForm("Unknow", "intern");
	if (form_err) {
		bureaucrat.signForm(*form_err);
		bureaucrat.executeForm(*form_err);
	}
	return (EXIT_SUCCESS);
}
