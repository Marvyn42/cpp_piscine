/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:12:15 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/01 19:07:55 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &weapon_name) : type(weapon_name) {
}

Weapon::~Weapon() {
}

std::string const &Weapon::getType() const {
	return (this->type);
}

void	Weapon::setType(std::string const &weapon_name) {
	this->type = weapon_name;
}
