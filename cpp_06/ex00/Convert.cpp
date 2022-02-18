/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:43:01 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/18 23:06:08 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Convert::Convert(std::string const & literal) : _literal(literal), _type(0), _c_res(0),
												_i_res(0), _f_res(0), _d_res(0),
												_specific_float(0), _specific_double(0) {
}

Convert::Convert(Convert const & cpy) : _literal("0"), _type(0), _c_res(0),
										_i_res(0), _f_res(0), _d_res(0),
										_specific_float(0), _specific_double(0) {
	*this = cpy;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Convert::~Convert() {
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Convert & Convert::operator=(Convert const & ref) {
	this->_c_res = ref._c_res;
	this->_i_res = ref._i_res;
	this->_f_res = ref._f_res;
	this->_d_res = ref._d_res;
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	Convert::PrintConvert() {
	switch (this->_type) {
		case 0:
			break;
		default:
			if (this->_specific_double || this->_specific_float)
				std::cout << "char: impossible" << std::endl;
			else if (!isprint(this->_c_res))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << this->_c_res << "'" << std::endl;
			if (this->_specific_double || this->_specific_float
				|| (this->_i_res == std::numeric_limits<int>::min()
				&& this->_literal != "-2147483648"))
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << this->_i_res << std::endl;
			std::cout << "float: " << this->_f_res << ((fmod(this->_f_res, 1.0f)) ? "f" : ".0f")
				<< std::endl;
			std::cout << "double: " << this->_d_res << ((fmod(this->_d_res, 1.0)) ? "" : ".0")
				<< std::endl;
	}
}

void	Convert::convertArg() {
	if (this->guessType() == false) {
		std::cerr << "Argument not valid." << std::endl
			<< "You must use a Char, Int, Float or Double." << std::endl;
	}
	void	(Convert::*convert[NB_CONV])(void) =
		{&Convert::conv_char, &Convert::conv_int, &Convert::conv_float, &Convert::conv_double};

	this->setType();
	for (size_t i = 0; i < NB_CONV; i++)
		(this->*convert[i])();
}

bool	Convert::guessType() {
	bool	(Convert::*isType[NB_CONV])(void) =
		{&Convert::isChar, &Convert::isInt, &Convert::isFloat, &Convert::isDouble};

	for (size_t i = 0; i < NB_CONV; i++) {
		if ((this->*isType[i])())
			return (true);
	}
	return (false);
}

void	Convert::setType() {
	std::stringstream	iss(this->_literal);

	switch (this->_type) {
		case CHAR:
			iss >> this->_c_res;
			break;
		case INT:
			iss >> this->_i_res;
			break;
		case FLOAT:
			if (this->_literal == "inff" || this->_literal == "+inff")
				this->_f_res = std::numeric_limits<float>::infinity();
			else if (this->_literal == "-inff")
				this->_f_res = std::numeric_limits<float>::infinity() * -1;
			else if (this->_literal == "nanf")
				this->_f_res = std::numeric_limits<float>::quiet_NaN();
			else
				iss >> this->_f_res;
			break;
		case DOUBLE:
			if (this->_literal == "inf" || this->_literal == "+inf")
				this->_d_res = std::numeric_limits<float>::infinity();
			else if (this->_literal == "-inf")
				this->_d_res = std::numeric_limits<float>::infinity() * -1;
			else if (this->_literal == "nan")
				this->_d_res = std::numeric_limits<float>::quiet_NaN();
			else
				iss >> this->_d_res;
			break;
	}
}

bool	Convert::isChar() {
	if (_literal.size() != 1 || isdigit(this->_literal.at(0)))
		return (false);
	this->_type = CHAR;
	return (true);
}

bool	Convert::isInt() {
	std::stringstream	iss(this->_literal);
	std::string			rest;

	iss >> this->_i_res;
	if (iss.bad() || iss.fail()) {
		iss.clear();
		return (false);
	}
	iss >> rest;
	if (!rest.empty())
		return (false);
	this->_type = INT;
	return (true);
}

bool	Convert::isFloat() {
	if (this->_literal == "nanf" || this->_literal == "+inff"
			|| this->_literal == "inff" || this->_literal == "-inff") {
		this->_specific_float = true;
		this->_type = FLOAT;
		return (true);
	}

	std::stringstream	iss(this->_literal);
	char				c;
	std::string			rest;

	iss >> this->_f_res >> c;
	if (iss.bad() || iss.fail()) {
		iss.clear();
		return (false);
	}
	iss >> rest;
	iss.clear();
	if (c != 'f' || !rest.empty())
		return (false);
	std::cout << std::setprecision(this->_literal.length() -2);
	this->_type = FLOAT;
	return (true);
}

bool	Convert::isDouble() {
	if (this->_literal == "nan" || this->_literal == "+inf"
			|| this->_literal == "inf" || this->_literal == "-inf") {
		this->_specific_double = true;
		this->_type = DOUBLE;
		return (true);
	}

	std::stringstream	iss(this->_literal);
	std::string			rest;

	iss >> this->_d_res;
	if (iss.bad() || iss.fail()) {
		iss.clear();
		return (false);
	}
	iss >> rest;
	iss.clear();
	if (!rest.empty())
		return (false);
	std::cout << std::setprecision(this->_literal.length() -1);
	this->_type = DOUBLE;
	return (true);
}

void	Convert::conv_char() {
	switch (this->_type) {
		case INT:
			this->_c_res = static_cast<char>(this->_i_res);
			break;
		case FLOAT:
			this->_c_res = static_cast<char>(this->_f_res);
			break;
		case DOUBLE:
			this->_c_res = static_cast<char>(this->_d_res);
			break;
	}
}

void	Convert::conv_int() {
	switch (this->_type) {
		case CHAR:
			this->_i_res = static_cast<int>(this->_c_res);
			break;
		case FLOAT:
			this->_i_res = static_cast<int>(this->_f_res);
			break;
		case DOUBLE:
			this->_i_res = static_cast<int>(this->_d_res);
			break;
	}
}

void	Convert::conv_float() {
	switch (this->_type) {
		case CHAR:
			this->_f_res = static_cast<float>(this->_c_res);
			break;
		case INT:
			this->_f_res = static_cast<float>(this->_i_res);
			break;
		case DOUBLE:
			this->_f_res = static_cast<float>(this->_d_res);
			break;
	}
}

void	Convert::conv_double() {
	switch (this->_type) {
		case CHAR:
			this->_d_res = static_cast<double>(this->_c_res);
			break;
		case INT:
			this->_d_res = static_cast<double>(this->_i_res);
			break;
		case FLOAT:
			this->_d_res = static_cast<double>(this->_f_res);
			break;
	}
}
