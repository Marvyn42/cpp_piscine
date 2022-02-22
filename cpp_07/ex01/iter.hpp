/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:07:19 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/22 02:29:28 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <stdlib.h>
# include <stdio.h>

# define TAB_SIZE 7

template< typename T >
void	iter(T *addr, size_t size, int (*f)(T const & elem)) {
	for (size_t i = 0; i < size; i++) {
		(*f)(addr[i]);
	}
}

#endif
