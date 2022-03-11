/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:11:10 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/11 13:17:14 by mamaquig         ###   ########.fr       */
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
#define NC "\e[0m"
#define REDB "\e[41m"
#define	SIZE_TAB 10

void	test_deep_and_shallow() {
	std::cout << REDB "\tSHALLOW copy" NC << std::endl;
	{
		std::cout << REDB "DÉBUT SCOPE" NC << std::endl;
		std::cout << "création d'un Dog sur la stack:" << std::endl;
		Dog dogo;
		std::cout << std::endl << "Affichage de ses idées:" << std::endl;
		dogo.getBrain()->printIdeas();
		std::cout << REDB "FIN SCOPE" NC << std::endl;
	}
	std::cout << std::endl;
	std::cout << "création d'un Dog sur la stack" << std::endl;
	Dog dogo;
	dogo.getBrain()->setIdeas("Changement d'idée.");
	std::cout << std::endl;
	std::cout << REDB "\tDEEP copy" NC << std::endl;
	{
		std::cout << REDB "DÉBUT SCOPE" NC << std::endl;
		std::cout << "création d'un Dog par copy:"<< std::endl << std::endl;
		Dog tmp = dogo;
		tmp.getBrain()->setIdeas("Une nouvelle idée.");
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
		std::cout << REDB "FIN SCOPE" NC << std::endl;
	}
	std::cout << REDB "Fin de function." NC << std::endl;
}

int main() {
	Animal	*tab[SIZE_TAB];
	
	std::cout << REDB "\tINITIALISATION du tableau." NC << std::endl;
	for (size_t i = 0; i < SIZE_TAB; i++) {
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "tab[" << i << "]" << std::endl;
		if (i < SIZE_TAB / 2)
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << REDB "\tAFFICHAGE et DELETE du tab." NC << std::endl;
	for (size_t i = 0; i < SIZE_TAB; i++)
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "tab[" << i << "] = " << tab[i]->getType() << " who can: "
		<< tab[i]->makeSound() << std::endl << "deleting process:" << std::endl;
		delete tab[i];
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl;
	test_deep_and_shallow();
	return (EXIT_SUCCESS);
}
