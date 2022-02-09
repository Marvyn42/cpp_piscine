/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:48:27 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/07 01:36:40 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(std::string const & type);
		Ice(Ice const & cpy);

		virtual ~Ice();

		Ice & operator=(Ice const &ref);

		void	setType(std::string type);

		virtual Ice		*clone() const;
		virtual void	use(ICharacter & target);
};

#endif
