/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:05:28 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/13 12:34:06 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	srand (time(NULL));

	switch (rand() % 3 + 1) {
		case 1:
			std::cout << "Class A is generated." << std::endl << std::endl;
			return (new A);
		case 2:
			std::cout << "Class B is generated." << std::endl << std::endl;
			return (new B);
		case 3:
			std::cout << "Class C is generated." << std::endl << std::endl;
			return (new C);
	}
	return (NULL);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A detected." << std::endl
			<< "Address = " << p << std::endl << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "B detected." << std::endl
			<< "Address = " << p << std::endl << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "C detected." << std::endl
			<< "Address = " << p << std::endl << std::endl;
	}
	else
		std::cout << "Error: unexpected ptr." << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A detected." << std::endl
			<< "Address = " << &p << std::endl;
	}
	catch(const std::exception& e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B detected." << std::endl
			<< "Address = " << &p << std::endl;
	}
	catch(const std::exception& e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C detected." << std::endl
			<< "Address = " << &p << std::endl;
	}
	catch(const std::exception& e) {}
	
}

int	main(void) {
	Base *ptr = generate();
	Base & ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;
	return (EXIT_SUCCESS);
}
