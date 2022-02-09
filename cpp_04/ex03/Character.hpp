/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:40:59 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/08 16:19:48 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# define TAB_SIZE 4

class Character : public ICharacter {
	public:
		Character();
		Character(std::string const & type);
		Character(Character const & cpy);

		virtual ~Character();

		Character & operator=(Character const &ref);

		void	printInventory();

		std::string const	& getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
	private:
		std::string		_name;
		unsigned int	_index;
		AMateria		*_inventory[4];
};

#endif
