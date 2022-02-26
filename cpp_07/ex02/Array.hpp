/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 02:31:06 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/22 12:35:14 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdlib.h>
# include <stdint.h>
# include <stdexcept>

template< typename T = int >
class Array {
	public:
		Array<T>() : _elem(0), _size(0) {}
		Array<T>(unsigned int n) : _elem(new T[n]), _size(n) {}
		Array<T>(Array<T> const & cpy) {*this = cpy;}

		virtual ~Array<T>() {delete[] _elem;}

		Array<T> & operator=(Array<T> const & ref) {
			_size = ref.size();
			_elem = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_elem[i] = ref._elem[i];
			return (*this);}

		T & operator[](size_t idx) {
			if (idx >= _size)
				throw std::out_of_range("Index insn't valid, it's out of range.");
			return (this->_elem[idx]);}

		size_t	size() const {return (this->_size);}

	private:
		T		*_elem;
		size_t	_size;
};

#endif
