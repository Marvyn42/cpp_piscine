/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:42:35 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/20 21:57:54 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cstdlib>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		
		void		announce();
		std::string	const getname();
		void		setname(std::string name);
	private:
		std::string _name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
