/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:50:42 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/10 19:16:04 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(DiamondTrap const &cpy) :	ClapTrap(cpy._Name),
													FragTrap(cpy._Name),
													ScavTrap(cpy._Name) {
	*this = cpy;
	std::cout << "Cpy DiamondTrap constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :	ClapTrap(name), FragTrap(name),
												ScavTrap(name), _Name(name) {
	std::cout << "Param DiamondTrap constructor" << std::endl;
	ClapTrap::_Name = name + "_clap_name";
	this->_Name = name;
	this->_HitPoints = FragTrap::getHP();
	this->_EnergyPoints = ScavTrap::getEP();
	this->_AttackDamage = FragTrap::getStaticAD();
	this->_Max_HP = FragTrap::getMax_HP();
	this->_Max_EP = ScavTrap::getMax_EP();
	this->_Type = "DiamondTrap";
	FragTrap::getStatus(this->_Type);
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

DiamondTrap::~DiamondTrap() {
	std::cout << "Default DiamondTrap destructor" << std::endl;
	FragTrap::getStatus("DiamondTrap");
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

DiamondTrap & DiamondTrap::operator=(DiamondTrap const &ref) {
	this->_Name = ref.getName();
	this->FragTrap::_HitPoints = ref.FragTrap::getHP();
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
**	Reproduit l'attaque de ScavTrap
*/
void	DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}

/*
**	Print le nom dans ClapTrap et DiamondTrap
*/
void	DiamondTrap::whoAmI() {
	std::cout << "ClapTrap's name is:\t" << ClapTrap::getName() << std::endl
		<< "DiamondTrap's name is:\t" << getName() << std::endl << std::endl;
}

/*
** Return his name
*/
std::string	DiamondTrap::getName() const {
	return (this->_Name);
}
