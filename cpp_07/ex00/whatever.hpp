/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:58:47 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/22 00:05:26 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template< typename T >
void	swap(T & a, T & b) {
	T c;

	c = b;
	b = a;
	a = c;
}

template< typename T >
T	min(T const & a, T const & b) {
	return ((a<b) ? a : b);
}

template< typename T>
T	max(T const & a, T const & b) {
	return((a>b) ? a : b);
}

#endif
