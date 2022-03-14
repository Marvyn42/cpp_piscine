/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 02:31:10 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/14 15:54:58 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

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
