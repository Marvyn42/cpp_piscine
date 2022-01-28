/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:31:18 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/27 20:53:41 by mamaquig         ###   ########.fr       */
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

		Fixed &	operator=(Fixed const &fix);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		
		float	toFloat() const;
		int		toInt() const;
	private:
		int					_fixedPoint;
		static int const	_fractionalBits = 8;
};

std::ostream &	operator<<(std::ostream &cout, Fixed const & fix);

#endif
