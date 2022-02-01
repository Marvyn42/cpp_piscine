/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 03:13:01 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/31 21:27:05 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(ScavTrap const &cpy);
		ScavTrap(std::string name);

		virtual ~ScavTrap();

		ScavTrap & operator=(ScavTrap const &);

		void guardGate(void) const;
		void attack(std::string const & target);
};

#endif
