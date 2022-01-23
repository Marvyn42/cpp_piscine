/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:43:35 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/20 21:57:27 by mamaquig         ###   ########.fr       */
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
**	Destructeur par défaut
*/
Zombie::~Zombie() {
	std::cout << this->getname() << " Died." << std::endl;
}

/*
**	Attribue un nom passé en paramètre à l'objet name
*/
void	Zombie::setname(std::string name) {
	this->_name = name;
}

std::string	const Zombie::getname() {
	return (this->_name);
}

void	Zombie::announce() {
	std::cout << this->getname() << " BraiiiiiiinnnzzzZ..." << std::endl;
}
