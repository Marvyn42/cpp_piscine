/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:13:36 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/01 19:37:00 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen() {
}

Karen::~Karen() {
}

void	Karen::complain(std::string level) {
	std::string	tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Karen::*f[4])(void) = {&Karen::_debug, &Karen::_info,
										&Karen::_warning, &Karen::_error};
	size_t		i = 0;

	while (level != tab[i] && i < 4)
		i++;
	switch (i) {
		case 0:
			(this->*f[0])();
			__attribute__ ((fallthrough));
		case 1:
			(this->*f[1])();
			__attribute__ ((fallthrough));
		case 2:
			(this->*f[2])();
			__attribute__ ((fallthrough));
		case 3:
			(this->*f[3])();
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	}
}

void	Karen::_debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my \
7XL-double-cheese-triple-pickle-special-ketchup burger. \
I just love it!" << std::endl << std::endl;
}
void	Karen::_info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. \
You don’t put enough! \
If you did I would not have to ask for it!" << std::endl << std::endl;
}
void	Karen::_warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming here for years and you just started working here \
last month." << std::endl << std::endl;
}
void	Karen::_error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, \
I want to speak to the manager now." << std::endl;
}
