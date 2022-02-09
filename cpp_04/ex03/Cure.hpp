/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:18:55 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/07 01:39:08 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(std::string const & type);
		Cure(Cure const & cpy);

		virtual ~Cure();

		Cure & operator=(Cure const &ref);

		void	setType(std::string type);

		virtual Cure	*clone() const;
		virtual void	use(ICharacter & target);
};

#endif
