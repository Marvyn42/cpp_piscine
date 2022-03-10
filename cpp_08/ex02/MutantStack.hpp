/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:04:52 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/04 15:04:02 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stdlib.h>
# include <iterator>
# include <stack>

template<typename T> class MutantStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type container_type;
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::value_type value_type;
		typedef typename std::stack<T>::size_type size_type;

		MutantStack(void) : std::stack<T>() {}
		MutantStack(MutantStack const& rhs) : std::stack<T>(rhs) { *this = rhs; }

		~MutantStack(void) {}

		iterator begin(void) { return (this->c.begin()); }
		iterator end(void) { return (this->c.end()); }
		iterator rbegin(void) { return (this->c.rbegin()); }
		iterator rend(void) { return (this->c.rend()); }

		MutantStack& operator=(MutantStack const& rhs) {
			if (this == &rhs)
				return (*this);
			std::stack<T>::operator=(rhs);
			return (*this);
		}
};

#endif
