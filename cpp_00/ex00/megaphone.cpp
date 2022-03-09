/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:41:22 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/01 14:25:00 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		for (int i = 1; i < ac; i++) {
			for (size_t j = 0; av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
			if (i != ac - 1)
				std::cout << " ";
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
