/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:42:34 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/18 22:45:03 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <cmath>
# include <iomanip>
# include <limits>

# define CHAR		1
# define INT		2
# define FLOAT		3
# define DOUBLE		4
# define NB_CONV	4

class Convert
{
	public:
		Convert(std::string const & literal = "0");
		Convert(Convert const & cpy);

		virtual ~Convert();

		Convert & operator=(Convert const & ref);

		void	convertArg();
		void	PrintConvert();

	private:
		const std::string	_literal;

		int			_type;
		char		_c_res;
		int			_i_res;
		float		_f_res;
		double		_d_res;
		int			_specific_float;
		int			_specific_double;

		bool	guessType();
		void	setType();

		bool	isChar();
		bool	isInt();
		bool	isFloat();
		bool	isDouble();

		void	conv_char();
		void	conv_int();
		void	conv_float();
		void	conv_double();
};

#endif
