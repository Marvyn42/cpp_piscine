/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 03:13:04 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/10 19:16:04 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

ScavTrap::ScavTrap() {
	this->_original = false;
	std::cout << "Default ScavTrap constructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &cpy) : ClapTrap::ClapTrap() {
	*this = cpy;
	std::cout << "Cpy SCAVTRAP constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap() {
	std::cout << "Param SCAVTRAP constructor" << std::endl;
	_Name = name;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	_Max_HP = 100;
	_Max_EP = 50;
	_original = true;
	_Type = "ScavTrap";
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

ScavTrap::~ScavTrap() {
	std::cout << "Default SCAVTRAP destructor" << std::endl;
	if (this->_original == false)
		getStatus(this->_Type);
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

ScavTrap & ScavTrap::operator=(ScavTrap const &ref) {
	this->_Name = ref.getName();
	this->_HitPoints = ref.getHP();
	this->_AttackDamage = ref.getAD();
	this->_EnergyPoints = ref.getEP();
	this->_Max_HP = ref.getMax_HP();
	this->_Max_EP = ref.getMax_EP();
	this->_Type = ref._Type;
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

/*
**	Je sais pas, je comprends pas en quoi c'est utile...
*/
void	ScavTrap::guardGate(void) const {
	std::cout << this->_Type << " " << getName()
		<< " has enterred in Gate keeper mode." << std::endl << std::endl;
}

/*
**	Affiche l'attaque de ScavTrap
*/
void	ScavTrap::attack(std::string const & target) {
	if (!this->_EnergyPoints) {
		std::cout << this->_Type << " " << this->_Name
			<< " is exhausted, he can no longer do something.\n" << std::endl;
		return ;
	}
	std::cout << this->_Type << " " << this->_Name << " BOMBARD " << target << ", causing "
		<< getAD() << "🗡️  DMG." << std::endl;
	this->_EnergyPoints--;
}
