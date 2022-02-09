/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:16:53 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/06 17:11:30 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

AAnimal::AAnimal() {
	std::cout << "Default AAnimal constructor" << std::endl;
	this->_type = "Unknow";
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "Param AAnimal constructor" << std::endl;
}

AAnimal::AAnimal(AAnimal const & cpy) {
	std::cout << "Cpy AAnimal constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

AAnimal::~AAnimal() {
	std::cout << "Default AAnimal destructor" << std::endl;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

AAnimal const &	AAnimal::operator=(const AAnimal & ref) {
	std::cout << "Surcharge d'opérateur AAnimal" << std::endl;
	this->_type = ref._type;
	return (*this);
}

std::ostream &	operator<<(std::ostream &cout, AAnimal const & ref) {
	cout << ref.getType();
	return (cout);
}

/* ************************************************************************** */
/* ************************************************************************** */

/*
**	modifie le _type
*/
void	AAnimal::setType(std::string ref) {
	this->_type = ref;
}

/*
**	retourne le _type
*/
std::string	AAnimal::getType() const {
	return (this->_type);
}
