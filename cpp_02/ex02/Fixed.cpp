/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:31:14 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/28 21:53:22 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Fixed::Fixed() : _fixedPoint(0) {
}

Fixed::Fixed(Fixed const &fix) {
	*this = fix;
}

Fixed::Fixed(const int integer) : _fixedPoint(integer << _fractionalBits) {
}

Fixed::Fixed(const float decimal) : _fixedPoint(roundf(decimal * (1 << _fractionalBits))) {
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Fixed::~Fixed() {
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Fixed const &	Fixed::operator=(Fixed const &fix) {
	this->_fixedPoint = fix.getRawBits();
	return (*this);
}

Fixed const	Fixed::operator+(Fixed const &fix) {
	return (Fixed(this->toFloat() + fix.toFloat()));
}

Fixed const	Fixed::operator-(Fixed const &fix) {
	return (Fixed(this->toFloat() - fix.toFloat()));
}

Fixed const	Fixed::operator*(Fixed const &fix) {
	return (Fixed(this->toFloat() * fix.toFloat()));
}

Fixed const	Fixed::operator/(Fixed const &fix) {
	return (Fixed(this->toFloat() / fix.toFloat()));
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	++*this;
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	--*this;
	return (tmp);
}

Fixed &	Fixed::operator++() {
	this->_fixedPoint++;
	return (*this);
}

Fixed &	Fixed::operator--() {
	this->_fixedPoint--;
	return (*this);
}

bool	Fixed::operator>(Fixed const &fix) {
	if (this->_fixedPoint > fix._fixedPoint)
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &fix) {
	if (this->_fixedPoint < fix._fixedPoint)
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &fix) {
	if (this->_fixedPoint >= fix._fixedPoint)
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &fix) {
	if (this->_fixedPoint <= fix._fixedPoint)
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &fix) {
	if (this->_fixedPoint == fix._fixedPoint)
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &fix) {
	if (this->_fixedPoint != fix._fixedPoint)
		return (true);
	return (false);
}


std::ostream &	operator<<(std::ostream &cout, Fixed const & fix) {
	cout << fix.toFloat();
	return (cout);
}

/* ************************************************************************** */
/* ************************************************************************** */

/*
**	Return value of _fixedPoint
*/
int		Fixed::getRawBits() const {
	return (this->_fixedPoint);
}

/*
**	Attribute raw to _fixedPoint
*/
void	Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;
}

/*
**	Return _fixedPoint to a float
*/
float	Fixed::toFloat() const {
	return ((float)_fixedPoint / (float)(1 << _fractionalBits));
}

/*
**	Return _fixedPoint to a int
*/
int		Fixed::toInt() const {
	return (_fixedPoint >> _fractionalBits);
}

/*
**	Return the lowest Fixed
*/
Fixed &	Fixed::min(Fixed & a, Fixed & b) {
	if (a > b)
		return (b);
	return (a);
}

/*
**	Return the lowest Fixed
*/
Fixed const & Fixed::min(Fixed const & a, Fixed const & b) {
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

/*
**	Return the highest Fixed
*/
Fixed &	Fixed::max(Fixed & a, Fixed & b) {
	if (a > b)
		return (a);
	return (b);
}

/*
**	Return the highest Fixed
*/
Fixed const & Fixed::max(Fixed const & a, Fixed const & b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
