/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:03:48 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/04 15:11:38 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void) {
	{
		MutantStack<int> mstack;

		mstack.push(17);
		mstack.push(5);

		std::cout << "top : " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "size : " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(12);
		mstack.push(987);
		mstack.push(29);
		mstack.push(1);
		mstack.push(-123);
		mstack.push(79888);
		mstack.push(2021);
		mstack.push(0);

		MutantStack<int>::iterator it  = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << std::endl;

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << std::endl << "My tests ------------" << std::endl << std::endl;

	{
		MutantStack<std::string> mutant_stack;

		std::cout << "mutant_stack is "
				  << (mutant_stack.empty() ? "empty." : "not empty.")
				  << std::endl;

		mutant_stack.push("Hello");		//0
		mutant_stack.push(" ");			//1
		mutant_stack.push("my");		//2
		mutant_stack.push(" ");			//3
		mutant_stack.push("name");		//4
		mutant_stack.push(" ");			//5
		mutant_stack.push("is");		//6
		mutant_stack.push(" ");			//7
		mutant_stack.push("Marvyn");	//8

		std::cout << "mutant_stack is "
				  << (mutant_stack.empty() ? "empty." : "not empty.")
				  << std::endl;

		std::cout << "mutant_stack size is " << mutant_stack.size() << "."
				  << std::endl;

		std::cout << "mutant_stack top elem is '" << mutant_stack.top() << "'.\n"
				  << std::endl;

		for (MutantStack<std::string>::iterator it = mutant_stack.begin();
			 it != mutant_stack.end();
			 it++)
			std::cout << *it;
		std::cout << std::endl;

		mutant_stack.pop();
		mutant_stack.push("toto");

		for (MutantStack<std::string>::iterator it = mutant_stack.begin();
			 it != mutant_stack.end();
			 it++)
			std::cout << *it;
		std::cout << std::endl;
	}
	return (EXIT_SUCCESS);
}
