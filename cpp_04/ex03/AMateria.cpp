/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:45:32 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/07 01:44:49 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

AMateria::AMateria() : type("Unknow") {
	std::cout << "Default AMateria constructor" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << "Param AMateria constructor" << std::endl;
}

AMateria::AMateria(AMateria const & cpy) {
	std::cout << "Cpy AMateria constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

AMateria::~AMateria() {
	std::cout << "Default AMateria destructor" << std::endl;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

AMateria &	AMateria::operator=(AMateria const & ref) {
	std::cout << "AMateria operator called" << std::endl;
	this->type = ref.getType();
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

/*
**
*/
std::string const & AMateria::getType() const {
	return (this->type);
}

void		AMateria::use(ICharacter & target) {
	std::cout << "* should do nothing to "<< target.getName() << " *" << std::endl;
}
