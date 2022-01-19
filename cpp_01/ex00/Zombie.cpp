/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:43:35 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/20 00:04:38 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
**	Constructeur par défaut
*/
Zombie::Zombie() {
	//créer un zombie sur la heap
}

/*
**	Constructeur avec param
*/
Zombie::Zombie(std::string name) : _name(name) {
}

/*
**	Destructeur par défaut
*/
Zombie::~Zombie() {
	std::cout << this->getname() << " Died." << std::endl;
}

std::string	const Zombie::getname() {
	return (this->_name);
}

void	Zombie::announce() {
	std::cout << this->getname() << " BraiiiiiiinnnzzzZ..." << std::endl;
}
