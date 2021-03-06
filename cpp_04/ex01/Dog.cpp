/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:16:56 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/03 01:46:49 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << "Default Dog constructor" << std::endl;
}

Dog::Dog(std::string type) : Animal(type), _brain(new Brain()) {
	std::cout << "Param Dog constructor" << std::endl;
}

Dog::Dog(Dog const & cpy) : Animal("Dog"), _brain(new Brain()) {
	std::cout << "Cpy Dog constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Dog::~Dog() {
	std::cout << "Default Dog destructor" << std::endl;
	delete this->_brain;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Dog const &	Dog::operator=(const Dog &ref) {
	std::cout << "Surcharge d'op??rateur Dog" << std::endl;
	Animal::operator=(ref);
	*this->_brain = *ref.getBrain();
	return (*this);
}

std::ostream &	operator<<(std::ostream &cout, Dog const & ref) {
	cout << ref.getType();
	return (cout);
}

/* ************************************************************************** */
/* ************************************************************************** */

std::string	Dog::makeSound() const {
		return ("WOUF WOUF !");
}

Brain	*Dog::getBrain() const {
	return (this->_brain);
}
