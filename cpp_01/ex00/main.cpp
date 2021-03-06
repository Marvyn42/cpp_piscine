/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:42:04 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/20 22:15:26 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie z1 = Zombie("Jason");
	Zombie *z2 = newZombie("Pascal");
	
	if (z2 == NULL) {
		std::cerr << "ERROR: Insufficient memory" << std::endl;
		return (EXIT_FAILURE);
	}
	z1.announce();
	randomChump("toto");
	z2->announce();
	delete z2;
	return (EXIT_SUCCESS);
}
