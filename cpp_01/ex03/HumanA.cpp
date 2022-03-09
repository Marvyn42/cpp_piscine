/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:01:49 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/01 19:14:27 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const &name, Weapon const &weapon) : _name(name),
																_weapon(weapon) {
}

HumanA::~HumanA()
{
}

void	HumanA::attack() {
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType() << std::endl;
}
