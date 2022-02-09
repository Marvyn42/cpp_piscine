/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:16:31 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/03 01:42:58 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const & cpy);

		virtual ~Animal();

		Animal const &	operator=(const Animal & ref);

		void			setType(std::string ref);
		std::string		getType() const;
		virtual std::string	makeSound() const;
		
	protected:
		std::string	_type;
};

std::ostream &	operator<<(std::ostream &cout, Animal const & ref);

#endif
