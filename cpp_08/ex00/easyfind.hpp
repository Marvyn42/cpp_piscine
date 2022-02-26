/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:34:59 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/24 14:01:24 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <list>
# include <vector>


template<typename T>
typename T::iterator	easyfind(T & container, int const & entier) {
	typename T::iterator it = container.begin();
	for (; it != container.end(); it++) {
		if (*it == entier)
			return (it);
	}
	throw std::runtime_error("Integer not found");
	return (it);
}

#endif
