/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:54:03 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/26 23:07:09 by mamaquig         ###   ########.fr       */
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
		Span(const size_t& size);
		Span(Span const & cpy);

		virtual ~Span();

		Span & operator=(Span const & ref);

		void			addNumber(int entier);
		void			shortestSpan();
		unsigned int	longestSpan();
		void			addNumbers(std::vector<int>::iterator begin,
							std::vector<int>::iterator end);

	private:
		const size_t		_size;
		std::vector<int>	_tab;
};

bool	value_not_valid(const size_t i);

#endif
