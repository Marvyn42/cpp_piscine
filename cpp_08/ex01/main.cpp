/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:53:40 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/26 20:06:25 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {
	try {
		Span test(3);
		test.addNumber(10);
		test.addNumber(20);
		test.addNumber(30);
		std::cout << test.longestSpan() << std::endl;
	} catch(std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}
