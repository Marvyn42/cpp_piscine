/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:32:31 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/11 03:59:49 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Form::Form(std::string const & name, uint32_t signeGrade, uint32_t execGrade) :
														_name(name), _signe(false),
														_signeGrade(signeGrade),
														_execGrade(execGrade) {
	if (this->_signeGrade < MAX_GRADE || this->_execGrade < MAX_GRADE)
		throw Form::GradeTooHighException();
	if (this->_signeGrade > MIN_GRADE || this->_execGrade > MIN_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & cpy) : _name(cpy.getName()), _signe(cpy.isSigned()),
								_signeGrade(cpy.get_signeGrade()),
								_execGrade(cpy.get_execGrade()) {
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Form::~Form() {
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Form & Form::operator=(Form const & ref) {
	(void)ref;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, Form & ref) {
	os << "┌───────────────────────────────────────┐" << std::endl
		<< "│ \tForm N°XX\t\t\t│" << std::endl << "│\tName: "
		<< ref.getName() << "\t\t\t│" << std::endl << "│ **** ********,\t\t\t│" << std::endl
		<< "│ *******, ************************. ** │" << std::endl
		<< "│ *** *****: ******.\t\t\t│" << std::endl << "│\t\t\t\t\t│" << std::endl
		<< "│ Grade necessary to signe:\t" << ref.get_signeGrade() << ".\t│" << std::endl
		<< "│ Grade necessary to exec:\t" << ref.get_execGrade() << ".\t│" << std::endl
		<< "│\t\t\t Signed: ";
		if (ref.isSigned())
			os << "✔️\t│" << std::endl;
		else
			os << "❌\t│" << std::endl;
		os << "└───────────────────────────────────────┘";

	return (os);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	Form::beSigned(Bureaucrat const & ref) {
	if (ref.getGrade() > this->_signeGrade)
		throw Form::GradeTooLowException();
	this->_signe = true;
	
}

std::string	Form::getName() const {
	return (_name);
}

bool		Form::isSigned() const {
	return (this->_signe);
}

uint32_t	Form::get_signeGrade() const {
	return (this->_signeGrade);
}

uint32_t	Form::get_execGrade() const {
	return (this->_execGrade);
}
