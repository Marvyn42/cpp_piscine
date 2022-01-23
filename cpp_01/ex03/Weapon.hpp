/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:53:46 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/22 18:10:11 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
	public:
		Weapon(std::string const &weapon_name);
		~Weapon();

		std::string const	&getType() const;
		void				setType(std::string const &weapon_name);
	private:
		std::string _weapon_type;
};

#endif
