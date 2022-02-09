/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:12:52 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/08 14:03:51 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCEE_HPP
# define MATERIASOURCEE_HPP

# include "IMateriaSource.hpp"
# define TAB_SIZE 4

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & cpy);

		virtual ~MateriaSource();

		MateriaSource & operator=(MateriaSource const & ref);

		void		printList();
		
		void		learnMateria(AMateria *ref);
		AMateria	*createMateria(std::string const & type);
		private:
			unsigned int	_index;
			AMateria		*_materias[4];
};

#endif
