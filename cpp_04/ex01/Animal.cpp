/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:16:53 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/03 01:42:51 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Animal::Animal() {
	std::cout << "Default Animal constructor" << std::endl;
	this->_type = "Unknow";
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Param Animal constructor" << std::endl;
}

Animal::Animal(Animal const & cpy) {
	std::cout << "Cpy Animal constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Animal::~Animal() {
	std::cout << "Default Animal destructor" << std::endl;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Animal const &	Animal::operator=(const Animal & ref) {
	std::cout << "Surcharge d'op??rateur Animal" << std::endl;
	this->_type = ref._type;
	return (*this);
}

std::ostream &	operator<<(std::ostream &cout, Animal const & ref) {
	cout << ref.getType();
	return (cout);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	Animal::setType(std::string ref) {
	this->_type = ref;
}

std::string	Animal::getType() const {
	return (this->_type);
}

std::string		Animal::makeSound() const {
	return ("Original copyright sound of an Animal.");
}
