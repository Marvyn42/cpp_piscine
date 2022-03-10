/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:55:10 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/27 22:36:53 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Span::Span(size_t size) : _size(size) {
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
	this->_size = ref._size;
	this->_tab = ref._tab;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, Span & ref) {
	for (size_t i = 0; i < ref.getSize() ; i++) {
		os << "tab[" << i << "] = " << ref[i] << std::endl;
	}
	return (os);
}

int &	Span::operator[](size_t idx) {
	if (idx >= this->_tab.size())
		throw std::runtime_error("Index out of range");
	return (this->_tab[idx]);
}

/* ************************************************************************** */
/*                                 ACCESSORS                                  */
/* ************************************************************************** */

size_t	Span::getSize() const{
	return (this->_tab.size());
}

/* ************************************************************************** */
/*                              MEMBER FUNCTION                               */
/* ************************************************************************** */

void	Span::addNumber(int entier) {
	if (this->_tab.size() == this->_size)
		throw std::runtime_error("No slot available.");
	this->_tab.push_back(entier);
}

void	Span::addNumbers(std::vector<int>::iterator begin,
			std::vector<int>::iterator end) {
	if (this->_tab.size() + std::distance(begin, end) > this->_size)
		throw std::runtime_error("No slot available.");
	this->_tab.insert(this->_tab.begin(), begin, end);
}

unsigned int	Span::shortestSpan() {
	if (this->_tab.size() < 2)
		throw std::runtime_error("Not enough integer to find a distance.");

	unsigned int span = std::numeric_limits<unsigned int>::max();

	for (std::vector<int>::const_iterator it = this->_tab.begin();
		 it != this->_tab.end();
		 it++) {
		for (std::vector<int>::const_iterator it2 = this->_tab.begin();
			 it2 != this->_tab.end();
			 it2++) {
			if (it != it2
				&& static_cast<unsigned int>(std::abs(*it - *it2)) < span)
				span = std::abs(*it - *it2);
		}
	}
	return (span);
}

unsigned int	Span::longestSpan() {
	if (this->_tab.size() <= 1)
		throw std::runtime_error("Not enough integer to find a distance.");
	return (*std::max_element(this->_tab.begin(), this->_tab.end())
		- *std::min_element(this->_tab.begin(), this->_tab.end()));
}

bool	Span::value_not_valid(const size_t i) {
	return ((static_cast<int>(i) < 0) ? 1 : 0);
}

/* ************************************************************************** */
/*                             NO MEMBER FUNCTION                             */
/* ************************************************************************** */

//
