/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:14:55 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/06 17:23:25 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(std::string type);
		Cat(Cat const & cpy);

		virtual ~Cat();

		Cat const &	operator=(const Cat &);

		virtual	std::string	makeSound() const;
		Brain	*getBrain() const;
		
	private:
		Brain *_brain;
};

std::ostream &	operator<<(std::ostream &cout, Cat const & ref);

#endif
