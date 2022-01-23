/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:59:47 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/22 18:51:56 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
	public:
		HumanB(std::string const &name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon const &weapon);
	private:
		std::string const	_name;
		Weapon const		*_weapon;
};

#endif
