/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:24:09 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/22 15:59:05 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int	main(void) {
	std::string const string = "HI THIS IS BRAIN";
	std::string const *stringPTR = &string;
	std::string const &stringREF = string;

	std::cout << &string << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl << std::endl;

	std::cout << string << std::endl;
	std::cout << string << std::endl;
	return (EXIT_FAILURE);
}
