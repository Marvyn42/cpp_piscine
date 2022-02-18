/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:02:19 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/18 19:05:46 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Number of argument not valid." << std::endl
			<< "Usage: ./convert [ARG]" << std::endl;
		return (EXIT_FAILURE);
	}

	Convert conv(av[1]);

	conv.convertArg();
	conv.PrintConvert();
	return (EXIT_SUCCESS);
}
