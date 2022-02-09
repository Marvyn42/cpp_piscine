/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:16:31 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/06 17:08:57 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const & cpy);

		virtual ~AAnimal();

		AAnimal const &	operator=(const AAnimal & ref);

		void			setType(std::string ref);
		std::string		getType() const;
		virtual std::string	makeSound() const = 0;
		
	protected:
		std::string	_type;
};

std::ostream &	operator<<(std::ostream &cout, AAnimal const & ref);

#endif
