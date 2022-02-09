/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:20:34 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/07 00:09:34 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Ice::Ice() : AMateria("ice") {
	std::cout << "Default Ice constructor" << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type) {
	std::cout << "Param Ice constructor" << std::endl;
}

Ice::Ice(Ice const & cpy) : AMateria() {
	std::cout << "Cpy Ice constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Ice::~Ice() {
	std::cout << "Default Ice destructor" << std::endl;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Ice &	Ice::operator=(Ice const & ref) {
	std::cout << "Ice operator called" << std::endl;
	AMateria::operator=(ref);
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

/*
**	Set the type
*/
void	Ice::setType(std::string type) {
	this->type = type;
}

/*
**
*/
Ice	*Ice::clone() const {
	return (new Ice(*this));
}

/*
**
*/
void	Ice::use(ICharacter & target) {
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}
