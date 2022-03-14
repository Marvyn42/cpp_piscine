/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:54:03 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/14 17:42:50 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <exception>
# include <vector>
# include <algorithm>

class Span
{
	public:
		Span(size_t size);
		Span(Span const & cpy);

		virtual ~Span();

		Span &	operator=(Span const & ref);
		int &	operator[](size_t idx);

		size_t	getSize() const;

		void			addNumber(int entier);
		bool			value_not_valid(const size_t i);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			addNumbers(std::vector<int>::iterator begin,
							std::vector<int>::iterator end);

	private:
		size_t				_size;
		std::vector<int>	_tab;
};

std::ostream & operator<<(std::ostream & os, Span & ref);

#endif
