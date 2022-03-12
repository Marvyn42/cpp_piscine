/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:32:31 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/12 14:27:51 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

AForm::AForm(std::string const & name, uint32_t signeGrade, uint32_t execGrade,
	std::string const & target) :	_name(name), _signe(false), _signeGrade(signeGrade),
									_execGrade(execGrade), _target(target) {
	if (this->_signeGrade < MAX_GRADE || this->_execGrade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (this->_signeGrade > MIN_GRADE || this->_execGrade > MIN_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & cpy) : _name(cpy.getName()), _signe(cpy.isSigned()),
								_signeGrade(cpy.get_signeGrade()),
								_execGrade(cpy.get_execGrade()),
								_target(cpy.getTarget()) {
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

AForm::~AForm() {
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

AForm & AForm::operator=(AForm const & ref) {
	(void)ref;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, AForm & ref) {
		os << "┌───────────────────────────────────────┐" << std::endl
			<< "│ \tForm N°XX\t\t\t│" << std::endl << "│\tName: "
			<< ref.getName() << "\t\t";
		if (ref.getName() != "Presidential")
			os << "\t";
		os << "│" << std::endl << "│ **** ********,\t\t\t│" << std::endl
			<< "│ *******, ************************. ** │" << std::endl
			<< "│ *** *****: ******.\t\t\t│" << std::endl << "│\t\t\t\t\t│" << std::endl
			<< "│ Target: " << ref.getTarget() << ".\t\t\t│" << std::endl
			<< "│ Grade necessary to signe:\t" << ref.get_signeGrade() << ".\t│" << std::endl
			<< "│ Grade necessary to exec:\t" << ref.get_execGrade() << ".\t│" << std::endl
			<< "│\t\t\t Signed: ";
		if (ref.isSigned())
			os << "✔️\t│" << std::endl;
		else
			os << "❌\t│" << std::endl;
		os << "└───────────────────────────────────────┘" << std::endl;

	return (os);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	AForm::beSigned(Bureaucrat const & ref) {
	if (ref.getGrade() > this->_signeGrade)
		throw AForm::GradeTooLowException();
	this->_signe = true;
	
}

std::string	AForm::getName() const {
	return (_name);
}

std::string	AForm::getTarget() const {
	return (_target);
}

bool		AForm::isSigned() const {
	return (this->_signe);
}

uint32_t	AForm::get_signeGrade() const {
	return (this->_signeGrade);
}

uint32_t	AForm::get_execGrade() const {
	return (this->_execGrade);
}

const char *	AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high.");
}

const char *	AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low.");
}
