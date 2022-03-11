/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:35:10 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/11 16:00:39 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <cstdlib>

// int main(void) {
// 	IMateriaSource* src = new MateriaSource();
// 	std::cout << std::endl;

// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	std::cout << std::endl;

// 	src->printList();
// 	std::cout << std::endl;

// 	ICharacter* me = new Character("me");
// 	std::cout << std::endl;

// 	AMateria* tmp;
// 	std::cout << std::endl;

// 	tmp = src->createMateria("ice");
// 	std::cout << tmp->getType() << std::endl;
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	std::cout << tmp->getType() << std::endl;
// 	me->equip(tmp);
// 	std::cout << std::endl;

// 	ICharacter* bob = new Character("bob");
// 	std::cout << std::endl;

// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	std::cout << std::endl;

// 	delete bob;
// 	delete me;
// 	delete src;
// 	std::cout << std::endl;

// 	return 0;
// }

int main(void) {
	MateriaSource* src1 = new MateriaSource();
	src1->learnMateria(new Cure());
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());
	src1->learnMateria(new Cure());
	src1->learnMateria(new Ice());
	std::cout << "========print source1 " << std::endl;
	src1->printList();

	std::cout << std::endl;

	MateriaSource* src2 = new MateriaSource();
	*src2				= *src1;
	std::cout << "========print source2 " << std::endl;
	src2->printList();

	std::cout << std::endl;

	Character* marvyn  = new Character("marvyn");
	Character* some_student = new Character();

	AMateria* tmp1;
	tmp1 = src2->createMateria("ice");
	marvyn->equip(tmp1);
	AMateria* tmp2;
	tmp2 = src1->createMateria("cure");
	marvyn->equip(tmp2);
	std::cout << std::endl;
	
	std::cout << "========print some_student inventory" << std::endl; 
	some_student->printInventory();
	std::cout << std::endl;

	std::cout << "========print marvyn inventory" << std::endl;
	marvyn->printInventory();
	std::cout << std::endl;

	*some_student = *marvyn;
	std::cout << std::endl;
	std::cout << "========print some_student inventory" << std::endl; 
	some_student->printInventory();
	std::cout << std::endl;

	Character* punching_ball = new Character("punching_ball");

	std::cout << "marvyn attacks punching_ball : " << std::endl;
	marvyn->use(0, *punching_ball);
	marvyn->use(1, *punching_ball);
	marvyn->use(99, *punching_ball);
	std::cout << std::endl;

	std::cout << "some_student attacks punching_ball : " << std::endl;
	some_student->use(0, *punching_ball);
	some_student->use(1, *punching_ball);
	std::cout << std::endl;

	marvyn->unequip(0);

	std::cout << "delete tmp1" << std::endl;
	delete tmp1;
	std::cout << std::endl;
	std::cout << "delete punching_ball" << std::endl;
	delete punching_ball;
	std::cout << std::endl;
	std::cout << "delete marvyn" << std::endl;
	delete marvyn;
	std::cout << std::endl;
	std::cout << "delete some_student" << std::endl;
	delete some_student;
	std::cout << std::endl;
	std::cout << "delete src1" << std::endl;
	delete src1;
	std::cout << std::endl;
	std::cout << "delete src2" << std::endl;
	delete src2;
	std::cout << std::endl;
	return 0;
}
