/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:53:40 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/27 00:22:42 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {
	std::vector<int> toto;
	std::vector<int> tata;
	toto.push_back(1);
	tata.push_back(1);
	toto.push_back(2);
	tata.push_back(2);
	toto.push_back(3);
	tata.push_back(3);
	toto.push_back(4);
	tata.push_back(4);
	try {
		Span test(10);
		test.addNumber(10);
		test.addNumber(20);
		test.addNumber(30);
		std::cout << test.longestSpan() << std::endl;
		test.addNumbers(toto.begin(), tata.end());
		std::cout << test << std::endl;
	} catch(std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}
