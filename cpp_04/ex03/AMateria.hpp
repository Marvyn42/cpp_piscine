/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:36:08 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/07 01:27:01 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>

class AMateria {
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & cpy);

		virtual ~AMateria();

		AMateria & operator=(AMateria const &ref);

		std::string const & getType() const;

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter & target);
	protected:
		std::string	type;
};

#endif
