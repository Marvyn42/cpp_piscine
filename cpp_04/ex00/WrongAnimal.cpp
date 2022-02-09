/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:46:14 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/01 19:49:55 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

WrongAnimal::WrongAnimal() {
	std::cout << "Default WrongAnimal constructor" << std::endl;
	this->_type = "Unknow";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "Param WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & cpy) {
	std::cout << "Cpy WrongAnimal constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

WrongAnimal::~WrongAnimal() {
	std::cout << "Default WrongAnimal destructor" << std::endl;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

WrongAnimal const &	WrongAnimal::operator=(const WrongAnimal & ref) {
	this->_type = ref._type;
	return (*this);
}

std::ostream &	operator<<(std::ostream &cout, WrongAnimal const & ref) {
	cout << ref.getType();
	return (cout);
}

/* ************************************************************************** */
/* ************************************************************************** */

std::string	WrongAnimal::getType() const {
	return (this->_type);
}

void		WrongAnimal::makeSound() const {
	std::cout << "Original copyright sound of an WrongAnimal." << std::endl;
}
