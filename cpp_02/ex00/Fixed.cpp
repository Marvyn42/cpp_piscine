/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:31:14 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/09 14:18:07 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fix) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const &fix) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPoint = fix.getRawBits();
	return (*this);
}

int		Fixed::getRawBits() const {
	std::cout << "getRawbits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawbits member function called" << std::endl;
	this->_fixedPoint = raw;
}
