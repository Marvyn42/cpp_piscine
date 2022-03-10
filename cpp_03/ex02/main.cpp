/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:04:20 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/10 19:03:23 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

std::string	parse(std::string number) {
	std::string input;
	std::cout << "Chose the name of the " << number << " Player:" << std::endl;
	std::cin >> input;
	return (input);
}

void	ClaptrapFight() {
	ClapTrap player1("Marvyn");
	ClapTrap player2;

	std::cout << std::endl;
	player1.attack(player2.getName());
	player2.takeDamage(player1.getAD());

	player2.beRepaired(5);
	player2.attack(player1.getName());
	player1.takeDamage(player2.getAD());

	player2.getStatus(player2.getType());
}

void	ScavtrapFight() {
	ScavTrap player1("Marvyn");
	ScavTrap player2;

	std::cout << std::endl;
	player1.attack(player2.getName());
	player2.takeDamage(player1.getAD());

	player2.beRepaired(5);
	player2.attack(player1.getName());
	player1.takeDamage(player2.getAD());

	player1.guardGate();
	player2.guardGate();
}

int	main(void) {
	std::cout << "-------------ClapTrap-------------" << std::endl;
	ClaptrapFight();
	std::cout << "\n\n";
	std::cout << "-------------ScavTrap-------------" << std::endl;
	ScavtrapFight();
	std::cout << "\n\n";
	std::cout << "-------------FragTrap-------------" << std::endl;

	FragTrap player1(parse("first"));
	std::cout << std::endl;
	FragTrap player2(parse("second"));
	int random;
	int bool_dice;

	srand (time(NULL));
	std::cout << std::endl;
	for (unsigned int i = 0; (player1.getHP() && player2.getHP())
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
		if ((player1.getHP() && player2.getHP()) && (player1.getEP() || player2.getEP())) {
			player1.getStatus(player1.getType());
			player2.getStatus(player2.getType());
			std::cout << std::endl;
		}
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
