/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:14:36 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/03 01:26:46 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const & cpy);

		virtual ~Dog();

		Dog const &		operator=(const Dog &ref);

		virtual	std::string	makeSound() const;
		Brain	*getBrain() const;

	private:
		Brain* _brain;
};

std::ostream &	operator<<(std::ostream &cout, Dog const & ref);

#endif
