/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:42:04 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/20 00:24:30 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie z1 = Zombie("Jason");
	Zombie *z2 = newZombie("Pascal");
	
	if (z2 == NULL) {
		std::cout << "ERROR: Insufficient memory";
	}
	z1.announce();
	randomChump("toto");
	z2->announce();
	delete z2;
	return (EXIT_SUCCESS);
}
