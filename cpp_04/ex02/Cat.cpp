/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:16:58 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/06 17:23:25 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
	std::cout << "Default Cat constructor" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type), _brain(new Brain()) {
	std::cout << "Param Cat constructor" << std::endl;
}

Cat::Cat(Cat const & cpy) : AAnimal("Cat"), _brain(new Brain()) {
	std::cout << "Cpy Cat constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Cat::~Cat() {
	std::cout << "Default Cat destructor" << std::endl;
	delete this->_brain;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Cat const &	Cat::operator=(const Cat &ref) {
	std::cout << "Surcharge d'opérateur Cat" << std::endl;
	AAnimal::operator=(ref);
	*this->_brain = *ref.getBrain();
	return (*this);
}

std::ostream &	operator<<(std::ostream &cout, Cat const & ref) {
	cout << ref.getType();
	return (cout);
}

/* ************************************************************************** */
/* ************************************************************************** */

std::string	Cat::makeSound() const {
		return ("MIAW MIAW MOTHER F*CKER !");
}

Brain	*Cat::getBrain() const {
	return (this->_brain);
}
