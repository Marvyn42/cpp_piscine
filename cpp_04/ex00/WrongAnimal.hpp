/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:45:17 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/01 21:12:29 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const & cpy);

		virtual ~WrongAnimal();

		WrongAnimal const &	operator=(const WrongAnimal & ref);

		std::string		getType() const;
		void			makeSound() const;
		
	protected:
		std::string	_type;
};

std::ostream &	operator<<(std::ostream &cout, WrongAnimal const & ref);

#endif
