/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:01:02 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/10 18:51:47 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap() {
	std::cout << "Param FragTrap constructor" << std::endl;
	_Name = name;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	_Max_HP = 100;
	_Max_EP = 100;
	_Type = "FragTrap";
	getStatus(this->_Type);
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap::ClapTrap() {
	*this = cpy;
	std::cout << "Cpy FragTrap constructor" << std::endl;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

FragTrap::~FragTrap() {
	std::cout << "Default FragTrap destructor" << std::endl;
	getStatus(this->_Type);
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

FragTrap & FragTrap::operator=(FragTrap const &ref) {
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
**	Affiche l'attaque de FragTrap
*/
void	FragTrap::attack(std::string const & target) {
	if (!this->_EnergyPoints) {
		std::cout << this->_Type << " " << this->_Name
			<< " is exhausted, he can no longer do something.\n" << std::endl;
		return ;
	}
	std::cout << this->_Type << " " << this->_Name << " BOMBARD " << target << ", causing "
		<< getAD() << "🗡️  DMG." << std::endl;
	this->_EnergyPoints--;
}


/*
**	Ask to his mate if he wants to highfive
*/
void	FragTrap::highFivesGuys() const {
	std::cout << "(っ´ω`)ﾉ (╥ω╥) " << std::endl
		<< getName() << " ask a HighFives to ";
}

/*
**	Accept to high five or not
*/
void	FragTrap::FairPlayOrNot(int respond) const {
	std::cout << getName() << "." << std::endl;
	if (respond == false) {
		std::cout << "(\"･_･)/ 凸(ಠ益ಠ凸) But " << getName()
			<< " aren't a good player. What a bad guy." << std::endl << std::endl;
	}
	else {
		std::cout << "ヽ(^ω^)人(^▽^)ﾉ " << getName()
			<< " has accepted. What a good player." << std::endl
			<< getName() << " is smart. Be like " << getName()
			<< "." << std::endl << std::endl;
	}
}
