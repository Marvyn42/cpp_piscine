/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:55:10 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/26 23:07:17 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Span::Span(const size_t& size) : _size(size) {
	if (value_not_valid(this->_size))
		throw std::runtime_error("Value cannot be accepted.");
}

Span::Span(Span const & cpy) : _size(cpy._size) {
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Span::~Span() {
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Span &	Span::operator=(Span const & ref) {
	(void)ref;
	return (*this);
}

/* ************************************************************************** */
/*                                 ACCESSORS                                  */
/* ************************************************************************** */

//

/* ************************************************************************** */
/*                              MEMBER FUNCTION                               */
/* ************************************************************************** */

void	Span::addNumber(int entier) {
	if (this->_tab.size() >= this->_size)
		throw std::runtime_error("No slot available.");
	this->_tab.push_back(entier);
}

void	Span::shortestSpan() {
	if (this->_tab.size() <= 1)
		throw std::runtime_error("Not enough integer to find a distance.");
}

unsigned int	Span::longestSpan() {
	if (this->_tab.size() <= 1)
		throw std::runtime_error("Not enough integer to find a distance.");
	return (*std::max_element(this->_tab.begin(), this->_tab.end())
		- *std::min_element(this->_tab.begin(), this->_tab.end()));
}

void	Span::addNumbers(std::vector<int>::iterator begin,
			std::vector<int>::iterator end) {
	//
}

/* ************************************************************************** */
/*                             NO MEMBER FUNCTION                             */
/* ************************************************************************** */

bool	value_not_valid(const size_t i) {
	return ((static_cast<int>(i) < 0) ? 1 : 0);
}
