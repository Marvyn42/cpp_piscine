/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:05:44 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/10 19:16:51 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

ClapTrap::ClapTrap() {
	this->_original = false;
	std::cout << "Default CLAPTRAP constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :	_Name(name), _HitPoints(10),
										_EnergyPoints(10), _AttackDamage(0),
										_Max_HP(10), _Max_EP(10), _original(true),
										_Type("ClapTrap") {
std::cout << "Param CLAPTRAP constructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cpy) {
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

ClapTrap::~ClapTrap() {
	std::cout << "Default CLAPTRAP destructor" << std::endl;
	if (this->_original == false)
		getStatus(this->_Type);
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

ClapTrap const &	ClapTrap::operator=(ClapTrap const &ref) {
	this->_Name = ref.getName();
	this->_HitPoints = ref.getHP();
	this->_AttackDamage = ref.getAD();
	this->_EnergyPoints = ref.getEP();
	this->_Max_HP = ref.getMax_HP();
	this->_Max_EP = ref.getMax_EP();
	return (*this);
}

/* ************************************************************************** */
/*                                 ACCESSORS                                  */
/* ************************************************************************** */

/*
**	Renvoi les HP actuel
*/
unsigned int const & ClapTrap::getHP() const {
	return (this->_HitPoints);
}

/*
**	Renvoi les HP max
*/
unsigned int const & ClapTrap::getMax_HP() const {
	return (this->_Max_HP);
}

/*
**	Renvoi les EP
*/
unsigned int const & ClapTrap::getEP() const {
	return (this->_EnergyPoints);
}

/*
**	Renvoi les EP max
*/
unsigned int const & ClapTrap::getMax_EP() const {
	return (this->_Max_EP);
}

/*
**	Renvoi l'AD
*/
unsigned int const & ClapTrap::getAD() const {
	return (this->_AttackDamage);
}

/*
**	Renvoi le nom
*/
std::string const & ClapTrap::getName() const {
	return (this->_Name);
}

/*
**	Renvoi le type
*/
std::string const & ClapTrap::getType() const {
	return (this->_Type);
}

/* ************************************************************************** */
/* ************************************************************************** */

/*
**	Effectue une attaque
*/
void	ClapTrap::attack(std::string const & target) {
	if (!this->_EnergyPoints) {
		std::cout << this->_Type << " " << this->_Name
			<< " is exhausted, he can no longer do something.\n" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing "
		<< getAD() << "🗡️  DMG." << std::endl;
	this->_EnergyPoints--;
}

/*
**	Reçois les dégats d'une attaque
*/
void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->_Type << " " << getName() << " has been attacked, causing "
	<< amount << "🩸 DMG." << std::endl;
	if (this->_HitPoints <= amount) {
		this->_HitPoints = 0;
		std::cout << "\t💀 " << this->_Type << " "<< getName() << " DIED 💀"
			<< std::endl << std::endl;
		return ;
	}
	else
		this->_HitPoints -= amount;
	std::cout << "He's left ";
	std::cout << RED "❤️  :" << getHP() << "/" << getMax_HP() << NC << "" << std::endl << std::endl;
}

/*
**	Se soigne de amount PV
*/
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_HitPoints != getMax_HP() && this->_EnergyPoints) {
		std::cout << "ClapTrap " << this->_Name << " heal himself from " << RED "❤️ "
			<< this->_HitPoints << "/" << getMax_HP() << NC " to ";
		while (this->_HitPoints < getMax_HP() && amount) {
			this->_HitPoints += 1;
			amount--;
		}
		this->_EnergyPoints--;
		std::cout << RED "❤️ " << this->_HitPoints << "/" << getMax_HP() << NC
			<< std::endl;
		}
}

/*
**	Affiche que le player à rater son attaque
*/
void	ClapTrap::missAttack() const {
	std::cout << "❌ " << this->_Name << " miss his attack ❌" << std::endl << std::endl;
}

/*
**	Affiche la vie, l'énergie et l'attaque du player
*/
void	ClapTrap::getStatus(std::string type) const {
	std::cout << "\t" << type << " " << REDB << getName() << NC << std::endl;
	std::cout << RED "❤️  :" << getHP() << "/" << getMax_HP() << NC;
	std::cout << CYN "\t⚡:" << getEP() << "/" << getMax_EP() << NC << " ";
	std::cout << GRN "\t🗡️  :"<< getAD() << NC << std::endl;
}
