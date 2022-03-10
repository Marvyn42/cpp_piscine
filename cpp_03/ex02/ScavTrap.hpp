/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 03:13:01 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/10 17:14:19 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name = "NONAME");
		ScavTrap(ScavTrap const &cpy);

		virtual ~ScavTrap();

		ScavTrap & operator=(ScavTrap const &);

		void	guardGate(void) const;
		void	attack(std::string const & target);
};

#endif
