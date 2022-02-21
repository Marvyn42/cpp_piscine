/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:06:35 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/21 00:00:36 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>
# include <stdlib.h>

class Data {
	public:
		Data(int i, std::string str);
		Data(Data const & cpy);

		virtual ~Data();

		Data & operator=(Data const & ref);

		int			entier;
		std::string	string;
};

std::ostream & operator<<(std::ostream & os, const Data& ref);

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
