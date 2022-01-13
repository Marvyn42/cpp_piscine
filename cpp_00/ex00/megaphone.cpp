/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:41:22 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/10 23:23:30 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		for (int i = 1; i < ac; i++)
			for (size_t j = 0; av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
