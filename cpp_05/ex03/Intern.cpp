/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:26:05 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/15 16:26:50 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Intern::Intern() : _form(NULL) {
}

Intern::Intern(Intern const & cpy) {
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Intern::~Intern() {
	delete this->_form;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Intern & Intern::operator=(Intern const & ref) {
	this->_form = ref._form;
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

AForm	*Intern::makeShrubberyCreation(std::string const & target) {
	delete this->_form;
	_form = new ShrubberyCreationForm(target);
	return (_form);
}

AForm	*Intern::makeRobotomyRequest(std::string const & target) {
	delete this->_form;
	_form = new RobotomyRequestForm(target);
	return (_form);
}

AForm	*Intern::makePresidentialPardon(std::string const & target) {
	delete this->_form;
	_form = new PresidentialPardonForm(target);
	return (_form);
}

AForm	*Intern::makeForm(std::string const & form_name, std::string const & target) {
	std::string name[3] =
		{"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	AForm* (Intern::*form[3])(std::string const &) = {&Intern::makeShrubberyCreation,
													&Intern::makeRobotomyRequest,
													&Intern::makePresidentialPardon};

	for (size_t i = 0; i < 3; i++) {
		if (form_name == name[i]) {
			std::cout << "Intern creates" << form_name << "." << std::endl;
			return ((this->*form[i])(target));
		}
	}
	std::cerr << "The name of the Form does not match with any of your forms."
		<< std::endl;
	return (NULL);
}
