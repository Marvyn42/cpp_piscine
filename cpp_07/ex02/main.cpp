/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 02:31:10 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/22 03:59:58 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
	Array<int> empty;
	std::cout << "Empty Tab as a size of " << empty.size() << std::endl;

	std::cout << std::endl;

	Array<int> tab(5);
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 3;
	tab[4] = 4;

	std::cout << "Tab as a size of " << tab.size() << std::endl;

	for (uint8_t i = 0; i < tab.size(); i++)
		std::cout << tab[i] << std::endl;
	std::cout << std::endl;

	// Testing assignation
	Array<int> tab_assign = tab;
	std::cout << "Tab Assign as a size of " << tab_assign.size()
			  << std::endl;
	for (uint8_t i = 0; i < tab_assign.size(); i++)
		std::cout << tab_assign[i] << std::endl;
	std::cout << std::endl;

	// Testing copy
	Array<int> tab_cpy(tab);
	std::cout << "Tab Copy as a size of " << tab_cpy.size() << std::endl;
	for (uint8_t i = 0; i < tab_cpy.size(); i++)
		std::cout << tab_cpy[i] << std::endl;
	std::cout << std::endl;

	// Testing out of range
	try {
		std::cout << "3rd element of tab is : " << tab[2] << std::endl;
		std::cout << "10th element of tab is : " << tab[9] << std::endl;
	} catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
	return (EXIT_SUCCESS);
}
