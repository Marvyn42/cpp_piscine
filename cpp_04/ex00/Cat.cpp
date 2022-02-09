/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:16:58 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/01 19:43:03 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Cat::Cat() : Animal("Cat") {
	std::cout << "Default Cat constructor" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Param Cat constructor" << std::endl;
}

Cat::Cat(Cat const & cpy) : Animal("Cat") {
	std::cout << "Cpy Cat constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Cat::~Cat() {
	std::cout << "Default Cat destructor" << std::endl;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Cat const &	Cat::operator=(const Cat &) {
	return (*this);
}

std::ostream &	operator<<(std::ostream &cout, Cat const & ref) {
	cout << ref.getType();
	return (cout);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	Cat::makeSound() const {
	std::cout << "MIAW MIAW MOTHER F*CKER !" << std::endl;
}

