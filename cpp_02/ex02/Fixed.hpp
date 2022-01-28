/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:31:18 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/28 21:53:32 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed(Fixed const &fix);
		Fixed(const int integer);
		Fixed(const float decimal);
		
		virtual ~Fixed();

		Fixed const &	operator=(Fixed const &fix);
		Fixed const		operator+(Fixed const &fix);
		Fixed const		operator-(Fixed const &fix);
		Fixed const		operator*(Fixed const &fix);
		Fixed const		operator/(Fixed const &fix);

		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed &	operator++();
		Fixed &	operator--();

		bool	operator>(Fixed const &fix);
		bool	operator<(Fixed const &fix);
		bool	operator>=(Fixed const &fix);
		bool	operator<=(Fixed const &fix);
		bool	operator==(Fixed const &fix);
		bool	operator!=(Fixed const &fix);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		
		float	toFloat() const;
		int		toInt() const;

		static Fixed &	min(Fixed & a, Fixed & b);
		static Fixed &	max(Fixed & a, Fixed & b);
		static const Fixed & min(Fixed const & a, Fixed const & b);
		static const Fixed & max(Fixed const & a, Fixed const & b);
		
	private:
		int					_fixedPoint;
		static int const	_fractionalBits = 8;
};

std::ostream &	operator<<(std::ostream &cout, Fixed const & fix);

#endif
