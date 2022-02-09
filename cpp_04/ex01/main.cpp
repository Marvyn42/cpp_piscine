/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:11:10 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/03 02:00:34 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#define	SIZE_TAB 10

void	test_deep_and_shallow() {
	std::cout << "\tShallow copy" << std::endl;
	{
		std::cout << "DÉBUT SCOPE" << std::endl;
		std::cout << "création d'un Dog sur la stack:" << std::endl;
		Dog dogo;
		std::cout << std::endl << "Affichage de ses idées:" << std::endl;
		dogo.getBrain()->printIdeas();
		std::cout << "FIN SCOPE" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "création d'un Dog sur la stack" << std::endl;
	Dog dogo;
	dogo.getBrain()->setIdeas("Changement d'idée.");
	std::cout << std::endl;
	std::cout << "\tDeep copy" << std::endl;
	{
		std::cout << "DÉBUT SCOPE" << std::endl;
		std::cout << "création d'un Dog par copy:"<< std::endl << std::endl;
		Dog tmp = dogo;
		std::cout << std::endl << "Affichage de ses idées:" << std::endl;
		std::cout << "dog tmp ideas = " << std::endl;
		tmp.getBrain()->printIdeas();
		std::cout << "dog dogo ideas = " << std::endl;
		dogo.getBrain()->printIdeas();
		std::cout << std::endl << "\taffichage addr brain" << std::endl;
		std::cout << "dogo = " << dogo.getBrain() << std::endl;
		std::cout << "tmp = " << tmp.getBrain() << std::endl;

		std::cout << std::endl << "\taffichage type dogo et tmp" << std::endl;
		std::cout << "type dogo =" << dogo.getType() << std::endl;
		std::cout <<"type tmp =" <<  tmp.getType() << std::endl;
		tmp.setType("changement de type");
		std::cout << "type dogo =" << dogo.getType() << std::endl;
		std::cout <<"type tmp =" <<  tmp.getType() << std::endl;
		dogo = tmp;
		std::cout << "type dogo =" << dogo.getType() << std::endl;
		std::cout <<"type tmp =" <<  tmp.getType() << std::endl << std::endl;
		std::cout << "FIN SCOPE" << std::endl;
	}
	std::cout << "Fin de function." << std::endl;
}

int main() {
	Animal	*tab[SIZE_TAB];
	
	std::cout << "Initialisation du tableau." << std::endl;
	for (size_t i = 0; i < SIZE_TAB; i++) {
		std::cout << "tab[" << i << "]" << std::endl;
		if (i < SIZE_TAB / 2)
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
	}
	std::cout << std::endl;
	for (size_t i = 0; i < SIZE_TAB; i++)
	{
		std::cout << "tab[" << i << "] = " << tab[i]->getType() << " who can: "
		<< tab[i]->makeSound() << std::endl << "deleting process:" << std::endl;
		delete tab[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	test_deep_and_shallow();
	return (EXIT_SUCCESS);
}
