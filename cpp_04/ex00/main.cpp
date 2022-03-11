/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:11:10 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/11 11:30:47 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void test_animal()
{
	std::cout << "ANIMAL ====" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "DOG ====" << std::endl;
	const Animal* dog = new Dog();
	std::cout << "CAT ====" << std::endl;
	const Animal* cat = new Cat();
	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete dog;
	delete cat;
	std::cout << std::endl;
}

void test_wrong_animal()
{
	std::cout << "===================================\n\n";
	std::cout << "Cat1 as WRONGANIMAL ====" << std::endl;
	const WrongAnimal* metawrong = new WrongCat();
	std::cout << std::endl;
	std::cout << "Cat2 as WRONGCAT ====" << std::endl;
	const WrongCat *Wc = new WrongCat();
	std::cout << std::endl << "cat1 :";
	metawrong->makeSound();
	std::cout << std::endl << "cat2 :";
	Wc->makeSound();
	std::cout << std::endl;
	delete metawrong;
	delete Wc;
}

int main()
{
	test_animal();
	test_wrong_animal();
}
