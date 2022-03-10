/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:05:44 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/10 15:57:25 by mamaquig         ###   ########.fr       */
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
	getStatus();
}

ClapTrap::ClapTrap(ClapTrap const &cpy) {
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

ClapTrap::~ClapTrap() {
	if (this->_original == false)
		getStatus();
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
/*                                 ACCESSORS                                  */
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
	if (!this->_EnergyPoints) {
		std::cout << "ClapTrap " << this->_Name
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
	std::cout << "ClapTrap " << this->_Name << " has been attacked, causing "
	<< amount << "🩸 DMG." << std::endl;
	if (this->_HitPoints <= amount) {
		this->_HitPoints = 0;
		std::cout << "💀 ClapTrap " << this->_Name << " DIED 💀" << std::endl << std::endl;
		return ;
	}
	else
		this->_HitPoints -= amount;
	std::cout << "He's left ";
	std::cout << RED "❤️  :" << this->_HitPoints << "/" << HP_MAX << NC << ""
		<< '\n' << std::endl;
}

/*
**	Se soigne de amount PV
*/
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_HitPoints != HP_MAX && this->_EnergyPoints) {
		std::cout << "ClapTrap " << this->_Name << " heal himself from " << RED "❤️ "
			<< this->_HitPoints << "/" << HP_MAX << NC " to ";
		while (this->_HitPoints < HP_MAX && amount) {
			this->_HitPoints += 1;
			amount--;
		}
		this->_EnergyPoints--;
		std::cout << RED "❤️ " << this->_HitPoints << "/" << HP_MAX << NC
			<< std::endl;
		}
}

void	ClapTrap::missAttack() const {
	std::cout << "❌ " << this->_Name << " miss his attack ❌"
		<< '\n' << std::endl;
}

void	ClapTrap::getStatus() const {
	std::cout << "\t" << "ClapTrap " << REDB << this->_Name << NC << std::endl;
	std::cout << RED "❤️  :" << this->_HitPoints << "/" << HP_MAX << NC;
	std::cout << CYN "\t⚡:" << this->_EnergyPoints << "/" << HP_MAX << NC << " ";
	std::cout << GRN "\t🗡️  :"<< getAD() << NC << std::endl;
}
