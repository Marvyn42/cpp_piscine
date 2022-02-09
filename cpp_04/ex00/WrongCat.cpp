/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:46:42 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/01 21:19:05 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Default WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "Param WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(WrongCat const & cpy) : WrongAnimal("WrongCat") {
	std::cout << "Cpy WrongCat constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

WrongCat::~WrongCat() {
	std::cout << "Default WrongCat destructor" << std::endl;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

WrongCat const &	WrongCat::operator=(const WrongCat &) {
	return (*this);
}

std::ostream &	operator<<(std::ostream &cout, WrongCat const & ref) {
	cout << ref.getType();
	return (cout);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	WrongCat::makeSound() const {
	std::cout << "MIOUF MIOu... WTF !" << std::endl;
}
