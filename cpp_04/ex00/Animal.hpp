/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:16:31 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/01 19:46:09 by mamaquig         ###   ########.fr       */
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

		std::string		getType() const;
		virtual void	makeSound() const;
		
	protected:
		std::string	_type;
};

std::ostream &	operator<<(std::ostream &cout, Animal const & ref);

#endif
