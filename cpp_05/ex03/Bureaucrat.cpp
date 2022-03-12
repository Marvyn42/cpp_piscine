/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:47:08 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/12 14:26:55 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(std::string const & name, uint32_t grade) :	_name(name),
																	_grade(grade) {
	if (this->_grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & cpy) : _name(cpy.getName()) {
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Bureaucrat::~Bureaucrat() {
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & ref) {
	this->_grade = ref._grade;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, Bureaucrat & ref) {
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade()
		<< "." << std::endl;
	return (os);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	Bureaucrat::signForm(AForm & form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "." << std::endl;
	}
	catch (std::exception const & e) {
		std::cerr << this->getName() << " couldn't sign " <<  form.getName() << " because "
			<< e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << " form." << std::endl;
	}
	catch (std::exception const & e) {
		std::cout << this->_name << " can not execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::UpGrade() {
	if (this->_grade - 1 < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::DownGrade() {
	if (this->_grade + 1 > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::string	Bureaucrat::getName() const {
	return (_name);
}

uint32_t	Bureaucrat::getGrade() const {
	return (_grade);
}

const char *	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high.");
}

const char *	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low.");
}
