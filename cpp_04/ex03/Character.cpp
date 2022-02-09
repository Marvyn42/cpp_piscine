/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:43:51 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/08 16:49:21 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <stdio.h>

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Character::Character() : _name("Unamed"), _index(0) {
	std::cout << "Default Character constructor" << std::endl;
	for (size_t i = 0; i < TAB_SIZE; i++)
		this->_inventory[i] = NULL;
	
}

Character::Character(std::string const & name) : _name(name), _index(0) {
	std::cout << "Param Character constructor" << std::endl;
	for (size_t i = 0; i < TAB_SIZE; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & cpy) {
	std::cout << "Cpy Character constructor" << std::endl;
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Character::~Character() {
	std::cout << "Default Character destructor" << std::endl;
	for (size_t i = 0; i < TAB_SIZE; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Character &	Character::operator=(Character const & ref) {
	std::cout << "Character operator called" << std::endl;
	this->_name = ref.getName();
	this->_index = ref._index;
	for (size_t i = 0; i < TAB_SIZE; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (ref._inventory[i])
			this->_inventory[i] = ref._inventory[i]->clone();
	}
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	Character::printInventory() {
	for (size_t i = 0; i < TAB_SIZE; i++)
		if (this->_inventory[i])
			std::cout << "type = " << this->_inventory[i]->getType() << "\t addr = " << this->_inventory[i] << std::endl;
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (this->_index < TAB_SIZE) {
		for (size_t i = 0; i < TAB_SIZE; i++) {
			if (!_inventory[i]) {
				this->_inventory[i] = m;
				this->_index += 1;
				return ;
			}
		}
	}
}

void Character::unequip(int idx) {
	if (idx < TAB_SIZE && idx >= 0) {
		this->_inventory[idx] = NULL;
		this->_index -= 1;
	}
}

void Character::use(int idx, ICharacter& target) {
	if ((idx < TAB_SIZE && idx >= 0) && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
