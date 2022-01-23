/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:12:04 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/23 20:04:43 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage:" << std::endl << "./Karen [LEVEL]" << std::endl;
		return (EXIT_FAILURE);
	}
	Karen	hysterical;
	
	hysterical.complain(av[1]);
	return (EXIT_SUCCESS);
}
