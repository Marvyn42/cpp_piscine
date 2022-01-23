/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:42:04 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/20 22:23:18 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int	N = 5;

	Zombie *Z = zombieHorde(N, "Shane");
	if (!Z) {
		std::cerr << "ERROR: Insufficient memory" << std::endl;
		return (EXIT_FAILURE);
	}
	for (int i = 0; i < N; i++) {
		Z[i].announce();
	}
	delete[] Z;
	return (EXIT_SUCCESS);
}
