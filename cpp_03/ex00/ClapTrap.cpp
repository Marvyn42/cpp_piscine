/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:05:44 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/30 21:35:16 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

ClapTrap::ClapTrap() {
	this->_original = false;
}

ClapTrap::ClapTrap(std::string name) :	_Name(name), _HitPoints(HP_MAX),
										_EnergyPoints(HP_MAX), _AttackDamage(AD),
										_original(true) {
	getSatus();
}

ClapTrap::ClapTrap(ClapTrap const &cpy) {
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

ClapTrap::~ClapTrap() {
	if (this->_original == false)
		getSatus();
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

ClapTrap const &	ClapTrap::operator=(ClapTrap const &ref) {
	this->_Name = ref.getName();
	this->_HitPoints = ref.getHP();
	this->_AttackDamage = ref.getAD();
	this->_EnergyPoints = ref.getEP();
	return (*this);
}

/* ************************************************************************** */
/*                                GET FUNCTIONS                                */
/* ************************************************************************** */

/*
**	Renvoi les HP
*/
unsigned int const & ClapTrap::getHP() const {
	return (this->_HitPoints);
}

/*
**	Renvoi les EP
*/
unsigned int const & ClapTrap::getEP() const {
	return (this->_EnergyPoints);
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

/* ************************************************************************** */
/* ************************************************************************** */

/*
**	Effectue une attaque
*/
void	ClapTrap::attack(std::string const & target) {
	std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing "
		<< getAD() << "🗡️  DMG." << std::endl;
}

/*
**	Reçois les dégats d'une attaque
*/
void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << getName() << " has been attacked, causing "
	<< amount << "🩸 DMG." << std::endl;
	if (this->_HitPoints <= amount) {
		this->_HitPoints = 0;
		std::cout << "💀 ClapTrap " << getName() << " DIED 💀" << std::endl << std::endl;
		return ;
	}
	else
		this->_HitPoints -= amount;
	std::cout << "He's left ";
	std::cout << RED "❤️  :" << getHP() << "/" << HP_MAX << NC << "" << std::endl << std::endl;
}

/*
**	Se soigne de amount PV
*/
void	ClapTrap::beRepaired(unsigned int amount) {
	unsigned int	tmp = amount;
	std::cout << "ClapTrap " << getName() << " heal himself from " << RED "❤️ "
		<< getHP() << "/" << HP_MAX << NC " to ";
	while (this->_HitPoints < HP_MAX && amount) {
		this->_HitPoints += 1;
		this->_EnergyPoints -= 1;
		amount--;
	}
	std::cout << RED "❤️ " << getHP() << "/" << HP_MAX << NC
		<< " using " CYN << tmp - amount << "⚡EP." NC << std::endl;
	std::cout << "He's left ";
	std::cout << CYN "⚡:" << getEP() << "/" << HP_MAX << NC << std::endl << std::endl;
}

void	ClapTrap::missAttack() const {
	std::cout << "❌ " << this->_Name << " miss his attack ❌" << std::endl << std::endl;
}

void	ClapTrap::getSatus() const {
	std::cout << "\t" << "ClapTrap " << REDB << getName() << NC << std::endl;
	std::cout << RED "❤️  :" << getHP() << "/" << HP_MAX << NC;
	std::cout << CYN "\t⚡:" << getEP() << "/" << HP_MAX << NC << " ";
	std::cout << GRN "\t🗡️  :"<< getAD() << NC << std::endl;
}
