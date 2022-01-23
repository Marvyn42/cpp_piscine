/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:12:04 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/23 22:34:48 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void) {
	Karen	hysterical;
	
	hysterical.complain("DEBUG");
	hysterical.complain("INFO");
	hysterical.complain("WARNING");
	hysterical.complain("ERROR");
	hysterical.complain("NOTHING");
	return (EXIT_SUCCESS);
}
