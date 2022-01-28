/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:31:14 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/27 23:25:01 by mamaquig         ###   ########.fr       */
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

Fixed::Fixed(const int integer) : _fixedPoint(integer << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float decimal) : _fixedPoint(roundf(decimal * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const &fix) {
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPoint = fix.getRawBits();
	return (*this);
}

std::ostream &	operator<<(std::ostream &cout, Fixed const & fix) {
	cout << fix.toFloat();
	return (cout);
}

int		Fixed::getRawBits() const {
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;
}

float	Fixed::toFloat() const {
	return ((float)_fixedPoint / (float)(1 << _fractionalBits));
}
int		Fixed::toInt() const {
	return (_fixedPoint >> _fractionalBits);
}
