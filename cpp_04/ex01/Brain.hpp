/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:12:48 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/03 00:23:15 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	public:
		Brain();
		Brain(Brain const & cpy);

		virtual ~Brain();

		Brain & operator=(Brain const &);

		void		printIdeas() const;
		std::string	getIdeas(unsigned int index) const;
		void		setIdeas(std::string idea);
	private:
		std::string ideas[100];
};

#endif
