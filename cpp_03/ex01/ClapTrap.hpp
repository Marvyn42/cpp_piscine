/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:04:55 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/10 17:24:56 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>

# define NC "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define CYN "\e[0;36m"
# define REDB "\e[41m"

# define AD		0

class ClapTrap {
	public:
		ClapTrap(std::string name = "NONAME");
		ClapTrap(ClapTrap const &cpy);

		ClapTrap const &	operator=(ClapTrap const &ref);
		
		virtual	~ClapTrap();

		unsigned int const & getHP() const;
		unsigned int const & getMax_HP() const;
		unsigned int const & getEP() const;
		unsigned int const & getMax_EP() const;
		unsigned int const & getAD() const;
		std::string const & getName() const;
		std::string const & getType() const;

		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	getStatus(std::string type) const;
		void	missAttack() const;
		
	protected:
		std::string		_Name;
		unsigned int	_HitPoints;
		unsigned int	_EnergyPoints;
		unsigned int	_AttackDamage;
		unsigned int	_Max_HP;
		unsigned int	_Max_EP;
		bool			_original;
		std::string		_Type;
};

#endif
