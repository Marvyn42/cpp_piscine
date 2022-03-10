/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:04:20 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/10 16:04:53 by mamaquig         ###   ########.fr       */
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
	for (unsigned int i = 0; i < 5 && (player1.getHP() && player2.getHP())
		&& (player1.getEP() || player2.getEP()); i++) {
		std::cout << REDB "******************** ROUND " << i+1
			<< " ********************" << NC << std::endl;

		if ((bool_dice = rand() % 3) == false)
			player1.beRepaired(random = rand() % player1.getHP() + 1);
		random = player1.getEP();
		player1.attack(player2.getName());
		if ((bool_dice = rand() % 2) && random)
			player2.takeDamage(player1.getAD());
		else if (random)
			player1.missAttack();

		if (!player2.getHP())
			break ;
		if ((bool_dice = rand() % 3) == false)
			player2.beRepaired(random = rand() % player2.getHP() + 1);
		random = player2.getEP();
		player2.attack(player1.getName());
		if ((bool_dice = rand() % 2) && random)
			player1.takeDamage(player2.getAD());
		else if (random)
			player2.missAttack();
		if (i < 4) {
			player1.getStatus();
			player2.getStatus();
			std::cout << std::endl;
		}
	}
	return (EXIT_SUCCESS);
}
