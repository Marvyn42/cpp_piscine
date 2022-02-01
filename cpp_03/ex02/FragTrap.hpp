/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:00:31 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/31 22:45:42 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const & ref);

		virtual ~FragTrap();

		FragTrap & operator=(FragTrap const & cpy);

		void	attack(std::string const & target);
		void	highFivesGuys() const;
		void	FairPlayOrNot(int respond) const;
};

#endif
