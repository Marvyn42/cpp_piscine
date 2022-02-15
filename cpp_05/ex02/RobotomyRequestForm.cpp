/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 01:40:58 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/15 14:17:50 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : 
	AForm("Robotomy", 72, 45, target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & cpy) : AForm(cpy) {
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

RobotomyRequestForm::~RobotomyRequestForm() {
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & ref) {
	(void)ref;
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->get_execGrade())
		throw AForm::GradeTooLowException();
	std::cout << "* some drilling noise *" << std::endl;
	srand (time(NULL));
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully."
				<< std::endl << std::endl;
	else
		std::cout << "Robotomize on " << this->getTarget() << " failed :(."
				<< std::endl << std::endl;
}
