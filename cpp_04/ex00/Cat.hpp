/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:14:55 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/01 19:42:02 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string type);
		Cat(Cat const & cpy);

		virtual ~Cat();

		Cat const &	operator=(const Cat &);

		virtual void	makeSound() const;
};

std::ostream &	operator<<(std::ostream &cout, Cat const & ref);

#endif
