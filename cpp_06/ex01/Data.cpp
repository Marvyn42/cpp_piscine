/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:07:02 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/21 00:02:25 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Data::Data(int i, std::string str) : entier(i), string(str) {
}

Data::Data(Data const & cpy) : entier(cpy.entier), string(cpy.string) {
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Data::~Data() {
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Data & Data::operator=(Data const & ref) {
	this->entier = ref.entier;
	this->string = ref.string;
	return (*this);
}

/* ************************************************************************** */
/*                              MEMBER FUNCTION                               */
/* ************************************************************************** */

//

/* ************************************************************************** */
/*                             NO MEMBER FUNCTION                             */
/* ************************************************************************** */

std::ostream & operator<<(std::ostream & os, const Data& ref) {
	os << "Address of class = " << &ref << std::endl
		<< "\tentier = " << ref.entier << std::endl
		<< "\tstring = " << ref.string << std::endl;
	return (os);
}

uintptr_t	serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
