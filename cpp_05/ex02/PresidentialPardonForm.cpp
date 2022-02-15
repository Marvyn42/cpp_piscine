/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 01:41:43 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/15 13:17:57 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : 
	AForm("Presidential", 25, 5, target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & cpy) : AForm(cpy) {
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

PresidentialPardonForm::~PresidentialPardonForm() {
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & ref) {
	(void)ref;
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->get_execGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " has been apologized by Zaphod Beeblebrox."
			<< std::endl;
}
