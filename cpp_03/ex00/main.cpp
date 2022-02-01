/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:04:20 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/31 19:23:34 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap Marvyn("Marvyn");
	ClapTrap Toto("Antoine");
	ClapTrap player1;
	ClapTrap player2;
	int random;
	int bool_dice;

	srand (time(NULL));
	bool_dice = rand() % 2;
	if (bool_dice == 1) {
		player1 = Marvyn;
		player2 = Toto;
	}
	else {
		player1 = Toto;
		player2 = Marvyn;
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < 5 && player1.getHP() && player2.getHP(); i++) {
		std::cout << REDB "******************** ROUND " << i+1
			<< " ********************" << NC << std::endl;

		if ((bool_dice = rand() % 2) && player1.getHP() != HP_MAX && player1.getEP())
			player1.beRepaired(random = rand() % player1.getEP() + 1);
		player1.attack(player2.getName());
		if ((bool_dice = rand() % 2) == false)
			player2.takeDamage(player1.getAD());
		else
			player1.missAttack();

		if (!player2.getHP())
			break ;
		if ((bool_dice = rand() % 2) && player2.getHP() != HP_MAX && player2.getEP())
			player2.beRepaired(random = rand() % player2.getEP() + 1);
		player2.attack(player1.getName());
		if (!(bool_dice = rand() % 2))
			player1.takeDamage(player2.getAD());
		else
			player2.missAttack();
	}
	return (EXIT_SUCCESS);
}
