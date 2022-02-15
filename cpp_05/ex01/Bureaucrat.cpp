/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:47:08 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/11 03:55:24 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	return (os);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	Bureaucrat::signForm(Form & form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "." << std::endl;
	}
	catch (std::exception const & e) {
		std::cerr << this->getName() << " couldn't sign " <<  form.getName() << " because "
			<< e.what() << std::endl;
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
