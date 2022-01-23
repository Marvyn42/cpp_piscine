/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:03:36 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/20 22:22:49 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie *zh = new Zombie[N];

	if (!zh)
		return (NULL);
	for (int i = 0; i < N; i++)
		zh[i].setname(name);
	return (zh);
}
