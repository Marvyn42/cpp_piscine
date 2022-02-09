/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:14:51 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/09 01:11:21 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

MateriaSource::MateriaSource() : _index(0) {
	std::cout << "Default MateriaSource constructor" << std::endl;
	for (size_t i = 0; i < TAB_SIZE; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & cpy) {
	std::cout << "Default MateriaSource cpy" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

MateriaSource::~MateriaSource() {
	std::cout << "Default MateriaSource destructor" << std::endl;
	for (size_t i = 0; i < TAB_SIZE; i++)
		if (this->_materias[i])
			delete this->_materias[i];
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

MateriaSource & MateriaSource::operator=(MateriaSource const & ref) {
	this->_index = ref._index;
	for (size_t i = 0; i < TAB_SIZE; i++) {
		if (this->_materias[i])
			delete this->_materias[i];
		if (ref._materias[i])
			this->_materias[i] = ref._materias[i]->clone();
	}
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

void		MateriaSource::printList() {
	for (size_t i = 0; i < this->_index; i++)
		std::cout << this->_materias[i]->getType() << std::endl;
}

void		MateriaSource::learnMateria(AMateria *ref) {
	this->_materias[this->_index] = ref;
	this->_index += 1;
}

AMateria	*MateriaSource::createMateria(std::string const & type) {
	for (size_t i = 0; i < this->_index; i++)
	{
		if (this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return (NULL);
}
