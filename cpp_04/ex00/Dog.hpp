/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:14:36 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/01 19:43:14 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const & cpy);

		virtual ~Dog();

		Dog const &		operator=(const Dog &);
		virtual void	makeSound() const;
};

std::ostream &	operator<<(std::ostream &cout, Dog const & ref);

#endif
