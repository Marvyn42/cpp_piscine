/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:46:05 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/15 14:22:15 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Bureaucrat bureaucrat("Bureaucrat", MAX_GRADE);
	std::cout << bureaucrat;

	Bureaucrat newbie("Newbie", MIN_GRADE);
	std::cout << newbie;

	std::cout << std::endl
			  << "Testing ShrubberyCreationForm ------------------" << std::endl
			  << std::endl;

	ShrubberyCreationForm shrubbery_creation("MyGarden");
	std::cout << shrubbery_creation << std::endl;

	bureaucrat.executeForm(shrubbery_creation); // Execute form without signing it
	bureaucrat.signForm(shrubbery_creation);
	bureaucrat.executeForm(shrubbery_creation);

	std::cout << std::endl;

	newbie.signForm(shrubbery_creation);
	newbie.executeForm(shrubbery_creation);

	std::cout << shrubbery_creation << std::endl;
	std::cout << std::endl
			  << "Testing RobotomyRequestForm --------------------" << std::endl
			  << std::endl;

	RobotomyRequestForm robotomy_request("Antoine");
	std::cout << robotomy_request << std::endl;

	bureaucrat.executeForm(robotomy_request); // Execute form without signing it
	bureaucrat.signForm(robotomy_request);
	bureaucrat.executeForm(robotomy_request);

	std::cout << std::endl;

	newbie.signForm(robotomy_request);
	newbie.executeForm(robotomy_request);

	std::cout << robotomy_request << std::endl;
	std::cout << std::endl
			  << "Testing PresidentialPardonForm -----------------" << std::endl
			  << std::endl;

	PresidentialPardonForm presidential_pardon("Marvyn");
	std::cout << presidential_pardon << std::endl;

	bureaucrat.executeForm(presidential_pardon); // Execute form without signing it
	bureaucrat.signForm(presidential_pardon);
	bureaucrat.executeForm(presidential_pardon);

	std::cout << std::endl;

	newbie.signForm(presidential_pardon);
	newbie.executeForm(presidential_pardon);
	std::cout << presidential_pardon << std::endl;
	return (EXIT_SUCCESS);
}
