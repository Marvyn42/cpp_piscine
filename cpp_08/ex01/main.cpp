/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:53:40 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/27 22:37:59 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>

#define LEN 10000

int main(void) {
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortest Span = " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span = " << sp.longestSpan() << std::endl;

	std::cout << std::endl
			  << "Testing with 2 values --------------------------" << std::endl
			  << std::endl;

	Span span(5);

	try {
		span.addNumber(5);
		span.addNumber(2);
		std::cout << "longest span is: " << span.longestSpan() << std::endl;
		std::cout << "shortest span is: " << span.shortestSpan() << std::endl;
	} catch (std::exception const& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "Testing with 6 random values ------------------" << std::endl
			  << std::endl;

	srand(time(NULL));
	std::vector<int> vec;
	for (unsigned int i = 0; i < 6; i++)
		vec.push_back(rand() % 100 + 1);

	std::cout << vec.at(0);
	for (unsigned int i = 1; i < 6; i++)
		std::cout << " | " << vec.at(i);
	std::cout << std::endl;

	Span s(6);
	try {
		s.addNumbers(vec.begin(), vec.end());
		std::cout << "longest span is: " << s.longestSpan() << std::endl;
		std::cout << "shortest span is: " << s.shortestSpan() << std::endl;
		std::cout << std::endl;
		s.addNumber(0); // We can not add one more number.
	} catch (std::exception const& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "Testing with " << LEN << " random values --------------------"
			  << std::endl
			  << std::endl;

	vec.clear();
	for (unsigned int i = 0; i < LEN; i++)
		vec.push_back(rand() % 9999999 + 1);

	Span s2(LEN);
	try {
		s2.addNumbers(vec.begin(), vec.end());
		std::cout << "longest span is: " << s2.longestSpan() << std::endl;
		std::cout << "shortest span is: " << s2.shortestSpan() << std::endl;
	} catch (std::exception const& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
