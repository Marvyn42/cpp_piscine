/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:49:53 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/01 01:38:38 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(DiamondTrap const &cpy);
		DiamondTrap(std::string name);

		virtual ~DiamondTrap();

		DiamondTrap & operator=(DiamondTrap const &);

		void	attack(std::string const & target);
		std::string	getName() const;
		void		whoAmI();
	private:
		std::string	_Name;
};

#endif
