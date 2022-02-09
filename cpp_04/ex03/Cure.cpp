/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 23:36:54 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/08 14:27:52 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Cure::Cure() : AMateria("cure") {
	std::cout << "Default Cure constructor" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type) {
	std::cout << "Param Cure constructor" << std::endl;
}

Cure::Cure(Cure const & cpy) : AMateria() {
	std::cout << "Cpy Cure constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Cure::~Cure() {
	std::cout << "Default Cure destructor" << std::endl;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Cure &	Cure::operator=(Cure const & ref) {
	std::cout << "Cure operator called" << std::endl;
	AMateria::operator=(ref);
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

/*
**	Set the type
*/
void	Cure::setType(std::string type) {
	this->type = type;
}

/*
**
*/
Cure	*Cure::clone() const {
	return (new Cure(*this));
}

/*
**
*/
void	Cure::use(ICharacter & target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
