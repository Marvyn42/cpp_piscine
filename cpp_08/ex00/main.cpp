/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:34:37 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/23 23:46:35 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void) {
	std::list<int>	nbr;
	std::vector<int> toto(42, 100);

	nbr.push_back(1);
	nbr.push_back(2);
	nbr.push_back(3);
	nbr.push_back(4);
	nbr.push_back(5);
	try {
		std::cout << *easyfind(nbr, 2) << '\n';
		std::cout << *easyfind(nbr, 1) << '\n';
		std::cout << *easyfind(toto, 1) << std::endl;
	}
	catch (std::exception const& e) {
		std::cerr << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}
