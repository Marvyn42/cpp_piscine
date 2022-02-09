/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:16:56 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/06 16:55:00 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Dog::Dog() : Animal("Dog") {
	std::cout << "Default Dog constructor" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Param Dog constructor" << std::endl;
}

Dog::Dog(Dog const & cpy) : Animal("Dog") {
	std::cout << "Cpy Dog constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Dog::~Dog() {
	std::cout << "Default Dog destructor" << std::endl;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Dog const &	Dog::operator=(const Dog &) {
	std::cout << "Surcharge d'opérateur Dog" << std::endl;
	return (*this);
}

std::ostream &	operator<<(std::ostream &cout, Dog const & ref) {
	cout << ref.getType();
	return (cout);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	Dog::makeSound() const {
	std::cout << "WOUF WOUF !" << std::endl;
}
