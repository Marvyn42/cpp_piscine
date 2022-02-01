/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:04:20 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/31 22:30:39 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

std::string	parse(std::string number) {
	std::string input;
	std::cout << "Chose the name of the " << number << " Player:" << std::endl;
	std::cin >> input;
	return (input);
}

int	main(void) {
	FragTrap player1(parse("first"));
	std::cout << std::endl;
	FragTrap player2(parse("second"));
	int random;
	int bool_dice;

	srand (time(NULL));
	std::cout << std::endl;
	for (unsigned int i = 0; player1.getHP() && player2.getHP(); i++) {
		std::cout << REDB "******************** ROUND " << i+1
			<< " ********************" << NC << std::endl;

		if ((bool_dice = rand() % 2) && player1.getHP() != player1.getMax_HP() && player1.getEP())
			player1.beRepaired(random = rand() % player1.getEP() + 1);
		player1.attack(player2.getName());
		if ((bool_dice = rand() % 2) == false)
			player2.takeDamage(player1.getAD());
		else
			player1.missAttack();

		if (!player2.getHP())
			break ;
		if ((bool_dice = rand() % 2) && player2.getHP() != player2.getMax_HP() && player2.getEP())
			player2.beRepaired(random = rand() % player2.getEP() + 1);
		player2.attack(player1.getName());
		if (!(bool_dice = rand() % 2))
			player1.takeDamage(player2.getAD());
		else
			player2.missAttack();
	}
	if (player1.getHP()) {
		player1.highFivesGuys();
		player2.FairPlayOrNot(bool_dice = rand() % 2);
	}
	else {
		player2.highFivesGuys();
		player1.FairPlayOrNot(bool_dice = rand() % 2);
	}
	return (EXIT_SUCCESS);
}
