/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:06:10 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/21 00:01:38 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main(void) {
	int entier = 42;
	std::string string = "Serialize";
	
	Data test(entier, string);

	std::cout << test << std::endl;
	std::cout << "serialize = " << serialize(&test) << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "deserialize = " << deserialize(serialize(&test)) << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << *deserialize(serialize(&test));
	std::cout << "-------------------" << std::endl;
	std::cout << test;
	std::cout << "-------------------" << std::endl;

	return (EXIT_SUCCESS);
}
