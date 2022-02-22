/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:06:55 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/22 02:29:36 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	print(char const & c) {
	return (putchar(c));
}

int	print(int const & c) {
	return (putchar(c));
}


int	main(void) {
	char charTab[TAB_SIZE] = {'M', 'a', 'r', 'v', 'y', 'n', '\n'};
	int intTab[TAB_SIZE] = {'M', 'a', 'r', 'v', 'y', 'n', '\n'};

	iter<char>(charTab, TAB_SIZE, print);
	iter<int>(intTab, TAB_SIZE, print);
	return (EXIT_SUCCESS);
}
